#include "basics/mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include "basics/finddialog.h"
#include <QDialog>
#include "ui_gotocell.h"
#include "basics/sortdialog.h"

void example1() {
    //Example1
    QLabel* label = new QLabel("Hello Qt");
    label->show();
}

void example2(QGuiApplication& app) {
    //Example 2
    QPushButton* button = new QPushButton("Button");
    button->connect(button,&QPushButton::clicked,[&](){
        app.quit();
    });
    button->show();
}

void example3() {
    //Example 3
    QWidget* window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox* spinBox = new QSpinBox();
    QSlider* slider = new QSlider(Qt::Horizontal);

    slider->setRange(0,130);
    spinBox->setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);
    //    QObject::connect(spinBox,&QSpinBox::valueChanged,slider,&QSlider::setValue);


    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));


    spinBox->setValue(35);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);

    window->show();
}

void gotocellDialog() {
    Ui::gotocell ui; // Only Design Form is created
    QDialog* dialog = new QDialog(); // Above design form is passed to QDialog
    ui.setupUi(dialog);
    dialog->show();
}

void sortDialog() {
    SortDialog* dialog = new SortDialog();
    dialog->show();
   }
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sortDialog();
    return a.exec();
}
