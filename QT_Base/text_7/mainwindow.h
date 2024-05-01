#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_move_btn_clicked();
    void on_get_pose_clicked();
    void on_change_clicked();
    void on_modaldlg_clicked();
    void on_msgbox_clicked();
    void on_file_dialog_clicked();
    void on_font_dlg_clicked();
    void on_color_dlg_clicked();
    void on_input_dialog_clicked();
    void on_progress_dlg_clicked();
};
#endif // MAINWINDOW_H
