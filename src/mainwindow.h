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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <QMainWindow>

#include "mltcontroller.h"
#include "ui_mainwindow.h"

#ifdef Q_WS_MAC
#   include "glwidget.h"
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &_filename, QWidget *parent = 0);
    ~MainWindow();
    void initializeMlt ();

private:
    void resizeEvent (QResizeEvent* event);
    void forceResize ();

    Ui_MainWindow* ui;
    MltController* mlt;
    QString filename;
#ifdef Q_WS_MAC
    GLWidget* gl;
    static void on_frame_show(mlt_consumer, MainWindow*, mlt_frame);
#endif

Q_SIGNALS:
    void showImageSignal(QImage);

public Q_SLOTS:
    void openVideo ();
    void play ();
    void pause ();
    void onShowFrame (void* frame, unsigned position);

};

#endif // MAINWINDOW_H
