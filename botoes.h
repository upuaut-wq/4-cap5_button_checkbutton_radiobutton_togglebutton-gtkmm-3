#ifndef GTKMM_BOTOES_H
#define GTKMM_BOTOES_H
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/separator.h>
#include <gtkmm/tooltip.h>

class Botoes: public Gtk::Window{
    public:
        Botoes();
        virtual ~Botoes();
    protected:
        //Var aux
        int x;

        //Sinais
        void on_btn_comum();
        //Sinal do tooltip
        bool on_btn_tooltip(int x, int y,bool keyboard_tooltip,const Glib::RefPtr<Gtk::Tooltip> &tooltip);
        void on_alt_img_button();
        void on_hid_button();

        //Widgets
        //Boxs
        Gtk::Box m_box_main;
        Gtk::Box m_box1;
        Gtk::Box m_box2;

        //Labels
        Gtk::Label m_lb1;
        Gtk::Label m_lb2;
        Gtk::Label m_lb3;
        Gtk::Label m_lb4;
        Gtk::Label m_lb5;

        //Botoes
        Gtk::Button m_btn;
        Gtk::CheckButton m_ck_btn;
        Gtk::ToggleButton m_tog_btn;
        Gtk::RadioButton m_rad_btn1;
        Gtk::RadioButton m_rad_btn2;

        //TooltipWindow
        Gtk::Window m_tooltip;
        Gtk::Label m_label_tp;
        
};



#endif //GTKMM_BOTOES_H