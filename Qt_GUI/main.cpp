#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Example1
//    QLabel* label = new QLabel("Hello Qt");
//    label->show();

    //Example 2
//    QPushButton* button = new QPushButton("Button");
//    button->connect(button,&QPushButton::clicked,[&](){
//        a.quit();
//    });
//    button->show();

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

    w.show();

    return a.exec();
}
