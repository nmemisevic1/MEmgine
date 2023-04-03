#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MEmgine.h"

class MEmgine : public QMainWindow
{
    Q_OBJECT

public:
    MEmgine(QWidget *parent = nullptr);
    ~MEmgine();

private:
    Ui::MEmgineClass ui;
};
