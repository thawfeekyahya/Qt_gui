#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include "finddialog.h"

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

void example4() {

}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog* dialog = new FindDialog;
    dialog->show();
    return a.exec();
}
