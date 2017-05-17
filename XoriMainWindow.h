#ifndef XORIMAINWINDOW_H
#define XORIMAINWINDOW_H


#include <QMainWindow>


class XoriMainWindow : public QMainWindow {

        Q_OBJECT

    public:
        explicit XoriMainWindow(QWidget* parent = 0);
        ~XoriMainWindow();

    private:
        void initXoriMenu();
};


#endif // XORIMAINWINDOW_H
