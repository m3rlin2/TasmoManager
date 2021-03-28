#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QNetworkInterface>
#include <QTreeWidgetItem>
#include <QProgressDialog>
#include <QCloseEvent>

#include "wizards/setupdevicedialog.h"
#include "wizards/updatedevicedialog.h"
#include "preferencesdialog.h"
#include "terminaldialog.h"
#include "selectserverdialog.h"
#include "device_options/deviceoptionswidget.h"

#include "app/devicemanager.h"
#include "app/mqttservermanager.h"
#include "app/preferencesmanager.h"

class DeviceColorWidget;
class PreferencesDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    DeviceManager *deviceManager;
    MQTTServerManager *serverManager;
    PreferencesManager *preferencesManager;

private slots:

    void on_actiontest_triggered();

    void on_actionPreferences_triggered();

    void on_connectButton_clicked();

    void on_deviceDiscovered(DeviceInfo deviceInfo);

    void on_deviceInfoUpdate(DeviceInfo deviceInfo);

    void on_terminalButton_clicked();

    void on_deviceList_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_webUIButton_clicked();

    void on_settingsButton_clicked();

    void on_actionAbout_triggered();

    void on_refreshButton_clicked();

    void on_deviceButton_clicked();

    void on_restartButton_clicked();

    void closeEvent(QCloseEvent *event);

    void on_mqttButton_clicked();

    void on_wifiButton_clicked();

    void on_deviceList_itemDoubleClicked(QTreeWidgetItem *item, int column);

    void on_firmwareButton_clicked();

private:
    Ui::MainWindow *ui;

    void updateInfoText();

    PreferencesDialog *preferencesDialog;
    DeviceOptionsWidget *deviceOptionsWidget = nullptr;

    Device *selectedDevice = nullptr;

};
#endif // MAINWINDOW_H
