#include <iostream>
#include <Mlt.h>

using namespace Mlt;

void SaveFrame(const char *filename, uint8_t *data, int width, int height)
{
    // Open file
    FILE *pFile = fopen(filename, "wb");
    if (pFile == NULL)
        return;

    // Write header
    fprintf(pFile, "P6\n%d %d\n255\n", width, height);

    // Write pixel data
    for (int y = 0; y < height; y++)
        fwrite(data + y * width * 3, 1, width * 3, pFile);

    // Close file
    fclose(pFile);

    printf("wrote %s\n", filename);
}

int main(int argc, char **argv)
{
    char *infilename = NULL;
    char *outfilename = NULL;
    int framenum = -1;

    if (argc == 1 || argc == 3)
    {
        printf("mextract <moviefile> [<framenumber> <output.ppm>]\n");
        return -1;
    }

    infilename = argv[1];
    if (argc == 4)
    {
        framenum = atoi(argv[2]);
        outfilename = argv[3];
    }

	Factory::init();

    Profile profile("");
    Producer producer(profile, infilename);
    profile.from_producer (producer);
    Consumer consumer(profile, "null");

    // Prevent scaling to the profile size.
    // Let the sdl consumer do all scaling.
    consumer.set("rescale", "none");

    // Automatically exit at end of file.
    consumer.set("terminate_on_pause", 1);

    consumer.connect(producer);

    producer.seek(framenum);

    double seconds = ((double) framenum / producer.get_fps());
    int minutes = seconds / 60.0;
    int hours = minutes / 60.0;

    printf("tc          = %02d:%02d:%011.8f\n", hours, minutes, seconds - ((minutes * 60) + (hours * 3600)));

    int width = 0;
    int height = 0;

    auto frame = consumer.get_frame();
    mlt_image_format format = mlt_image_rgb24;
    auto image = frame->get_image(format, width, height);

    SaveFrame(outfilename, image, width, height);

    std::cout << width << " " << height << std::endl;

	Factory::close();
	return 0;
}
