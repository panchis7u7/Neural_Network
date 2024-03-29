#include "ui/ui_MainWindow.h"
#include <include/MainWindow.hpp>
#include <include/SerialPort.hpp>
#include <include/SerialPort.hpp>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QStringList qSerialPortList;
    for(const auto& serialPort : SerialPort::getAvailablePorts())
        qSerialPortList << QString::fromStdString(serialPort);
    ui->cbxComPorts->addItems(qSerialPortList);
}

MainWindow::~MainWindow() {
    if(m_spPort) delete m_spPort;
    delete ui;
}

void MainWindow::on_cbxComPorts_activated(int index) {
    (void)index; 
}

void MainWindow::on_pbConnectSerial_clicked() {
    QString selectedItem = ui->cbxComPorts->currentText();
    if(selectedItem != "") {
        m_spPort = new SerialPort(selectedItem.toStdString(), PortUtils::Serial::BaudRate::B9600);
        m_spPort->connect();
    }
}

