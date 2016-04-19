#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QString>
#include "Order.h"
#include "inventory.h"
#include <QLineEdit>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void button_factory(string name, int position);

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

    void on_done_button_clicked();

    void set_button_style(QPushButton *button);

    void clear_items(QLayout *layout);

    void update_list();

    void update_totals();

    void on_no_confirmbutton_clicked();

    void on_yes_confirm_button_clicked();

    void on_receipt_done_button_clicked();

    void on_password_enter_button_clicked();

    void on_inventory_done_button_clicked();

    void on_password_box_editingFinished();

    void on_hamburger_inv_button_clicked();

    void on_manage_back_button_clicked();

    void on_hotdog_inv_button_clicked();

    void on_chick_sand_inv_button_clicked();

    void on_chick_nug_inv_button_clicked();

    void on_salad_inv_button_clicked();

    void on_fries_inv_button_clicked();

    void on_soft_drink_inv_button_clicked();

    void on_tea_inv_button_clicked();

    void on_milkshake_inv_button_clicked();

private:
    Ui::MainWindow *ui;
    Order *new_order;
    Inventory *new_Inventory;
};

#endif // MAINWINDOW_H
