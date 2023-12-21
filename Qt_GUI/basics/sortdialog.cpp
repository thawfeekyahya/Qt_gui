#include <QtWidgets>
#include "sortdialog.h"

SortDialog::SortDialog(QWidget* parent)
    : QDialog(parent)
{
    setupUi(this);

    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A','Z');

}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    comboBox_2->clear();
    tertiaryColumnCombo->clear();

    comboBox_2->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));
    primaryColumnCombo->setMinimumSize(comboBox_2->sizeHint());

    QChar ch = first;
    while (ch <= last) {
        primaryColumnCombo->addItem(QString(ch));
        comboBox_2->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = static_cast<QChar>(ch.unicode() +1);
    }
}
