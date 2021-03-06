/*
 * Copyright (c) 2011 Dan Dennedy <dan@dennedy.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget (QWidget *parent = 0);
    ~GLWidget ();

    QSize minimumSizeHint () const;
    QSize sizeHint () const;
    void setImageAspectRatio (double ratio) {
        m_display_ratio = ratio;
    }

private:
    int x, y, w, h;
    int m_image_width, m_image_height;
    GLuint m_texture;
    double m_display_ratio;

public Q_SLOTS:
    void showImage (QImage image);

protected:
    void initializeGL ();
    void resizeGL (int width, int height);
    void resizeEvent (QResizeEvent* event);
    void paintGL ();
};

#endif
