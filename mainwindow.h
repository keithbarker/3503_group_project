#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_hamburger_button_clicked();

    void on_hotdog_button_clicked();

    void on_chick_sand_button_clicked();

    void on_chick_nug_button_clicked();

    void on_salad_button_clicked();

    void on_fries_button_clicked();

    void on_soda_button_clicked();

    void on_tea_button_clicked();

    void on_milk_shake_button_clicked();

    void on_admin_button_clicked();

    void on_checkout_button_clicked();

    void on_admin_button_2_clicked();

    void on_bacon_button_clicked();

    void on_cheese_button_clicked();

    void on_lettuce_button_clicked();

    void on_tomatoes_button_clicked();

    void on_pickles_button_clicked();

    void on_onions_button_clicked();

    void on_ketchup_button_clicked();

    void on_mustard_button_clicked();

    void on_bbq_button_clicked();

    void on_mayo_button_clicked();

    void on_done_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
