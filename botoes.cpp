#include "botoes.h"
#include <iostream>

Botoes::Botoes():m_tooltip(Gtk::WINDOW_POPUP){ //Define o tipo de Window para tooltip
    //set Orientation
    this->m_box_main.set_orientation(Gtk::ORIENTATION_HORIZONTAL); //Orientação da box
    this->m_box1.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_box2.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Window config
    this->set_border_width(7);  //Adiciona borda de 7 px na window
    this->set_title("Botões");

    //Cria estrutura
    this->add(this->m_box_main);
    this->m_box_main.pack_start(this->m_box1);
    this->m_box1.set_spacing(7);   //Adiciona spaço entre os filhos de 7px
    this->m_box1.set_homogeneous(true);    //Faz com que os filhos tenham o mesmo tamanho, Ajuda no alinhamento
    this->m_box_main.pack_start(this->m_box2);
    this->m_box2.set_homogeneous(true);
    this->m_box2.set_spacing(7);    //Adiciona spaço entre os filhos de 7px

    //Nome botoes
    this->m_btn.set_label("➊ - Priximo");
    this->m_ck_btn.set_label("Botão Liga desliga");
    this->m_tog_btn.set_image_from_icon_name("gtk-go-down",Gtk::ICON_SIZE_BUTTON);
    this->m_tog_btn.set_label("Precione");
    this->m_tog_btn.set_always_show_image(true);
    this->m_rad_btn1.set_label("Radio1");
    this->m_rad_btn2.set_label("Radio2");

    //Adiciona os labels/ Alinha Label
    this->m_box1.pack_start(this->m_lb1);
    this->m_lb1.set_valign(Gtk::ALIGN_CENTER);
    this->m_lb1.set_halign(Gtk::ALIGN_END);
    this->m_box1.pack_start(this->m_lb2);
    this->m_lb2.set_valign(Gtk::ALIGN_CENTER);
    this->m_lb2.set_halign(Gtk::ALIGN_END);
    this->m_box1.pack_start(this->m_lb3);
    this->m_lb3.set_valign(Gtk::ALIGN_CENTER);
    this->m_lb3.set_halign(Gtk::ALIGN_END);
    this->m_box1.pack_start(this->m_lb4);
    this->m_lb4.set_valign(Gtk::ALIGN_CENTER);
    this->m_lb4.set_halign(Gtk::ALIGN_END);
    this->m_box1.pack_start(this->m_lb5);
    this->m_lb5.set_valign(Gtk::ALIGN_CENTER);
    this->m_lb5.set_halign(Gtk::ALIGN_END);

    //Adiciona nome aos labels.
    this->m_lb1.set_label("Botão Normal ➠ ");
    this->m_lb2.set_label("Botão Liga Desliga ➠ ");
    this->m_lb3.set_label("Botão Check Button ➠ ");
    this->m_lb4.set_label("Botão de Escolha 1 ➠ ");
    this->m_lb5.set_label("Botão de Escolha 2 ➠ ");

    //Alinhamento dos botoes
    this->m_btn.set_valign(Gtk::ALIGN_CENTER);
    this->m_ck_btn.set_valign(Gtk::ALIGN_CENTER);
    this->m_tog_btn.set_valign(Gtk::ALIGN_CENTER);
    this->m_rad_btn1.set_valign(Gtk::ALIGN_CENTER);
    this->m_rad_btn2.set_valign(Gtk::ALIGN_CENTER);

    //Adicionar os botoes nas caixas
    this->m_box2.pack_start(this->m_btn);
    this->m_box2.pack_start(this->m_tog_btn);
    this->m_box2.pack_start(this->m_ck_btn);
    this->m_box2.pack_start(this->m_rad_btn1);
    this->m_box2.pack_start(this->m_rad_btn2);

    //Cria grupo para o Radio Buton
    Gtk::RadioButton::Group r_group;  //Cria um grupo para os radio button
    this->m_rad_btn1.set_group(r_group); //Adiciona os radio buttons ao grupo
    this->m_rad_btn2.set_group(r_group);

    //Configura Botão 1==================================================================================
    this->m_btn.set_tooltip_text("✔ - Pode ser adicionado tudo o que foi mostrado no cap3\n✔ - https://github.com/upuaut-wq/cap3_basico.git");
    //Cria Sinal
    this->m_btn.signal_clicked().connect(sigc::mem_fun(*this,&Botoes::on_btn_comum));
    this->x = 1; //Estado do botão comum
    std::cout << "x = 1" << std::endl;

    //Configura Botão 2=================================================================================
    //Cria configuração do ultimpo tooltip
    //Configure TooltipWindow
    this->m_tog_btn.set_tooltip_window(this->m_tooltip);
    this->m_label_tp.set_label(" O tooltip ficou para este botão ,\n  pois, não conseguir desativer depois de ativar...");
    this->m_tooltip.add(this->m_label_tp);
    this->m_tooltip.set_default_size(300,50);
    this->m_label_tp.show();

    //Cria Sinal tooltip para tooltipwindow
    this->m_tog_btn.signal_query_tooltip().connect(sigc::mem_fun(*this,&Botoes::on_btn_tooltip));
    this->m_tog_btn.signal_toggled().connect(sigc::mem_fun(*this,&Botoes::on_alt_img_button));

    //Configura Botão 3================================================================================
    this->m_ck_btn.set_tooltip_text(" Pode ser adicionado imagem e label juntos. \n Todos os tipos de tooltips tbm...");
    this->m_ck_btn.set_image_from_icon_name("gtk-apply",Gtk::ICON_SIZE_BUTTON);
    this->m_ck_btn.set_label("Desativar BTNs");
    this->m_ck_btn.set_always_show_image(true);
    this->m_ck_btn.set_image_position(Gtk::POS_RIGHT);
    this->m_ck_btn.signal_clicked().connect(sigc::mem_fun(*this,&Botoes::on_hid_button));
    this->show_all_children();

    //Configuração Botão 4 RADIO BUTONS=================================================================
    this->m_rad_btn1.set_image_from_icon_name("emblem-ohno",Gtk::ICON_SIZE_DIALOG);
    this->m_rad_btn2.set_image_from_icon_name("emblem-OK",Gtk::ICON_SIZE_DIALOG);
    this->m_rad_btn1.set_always_show_image(true);
    this->m_rad_btn2.set_always_show_image(true);
    //Sinal para alterar as imagens
    this->m_rad_btn1.signal_clicked().connect(sigc::mem_fun(*this,&Botoes::on_togbtn_alt));
    this->m_rad_btn2.signal_clicked().connect(sigc::mem_fun(*this,&Botoes::on_togbtn_alt));

    this->m_rad_btn1.set_tooltip_text("Aceita tooltip igual aos botoes comuns...");
    this->m_rad_btn2.set_tooltip_text("Aceita somente image ou somente label...");

}

Botoes::~Botoes(){

}

void Botoes::on_btn_comum(){
    const Glib::ustring num[10] = {"➊","➋","➌","➍","➎","➏","➐","➑","➒","➓"};
    std::cout << this->x << std::endl;
    switch (this->x)
    {
        case 1:{
            this->m_btn.set_tooltip_text("Tooltip do tipo texto.");
            this->m_btn.set_label(num[this->x] + " - Priximo");
            this->x = 2;
            break;
        }
        case 2:{
          
            this->m_btn.set_tooltip_markup("<span foreground=\"red\" size=\"medium\">ToolTip com Tags</span>!!!");
            this->m_btn.set_label(num[this->x] + " - Priximo");
            this->x = 3;
            break;
        }
        case 3:{
            this->m_btn.set_tooltip_text("Este ultimo era para ser um tooltip do tipo \n Window, mas depois que eu set_tooltip_window \n nao consigo mudar para text ou markup.");
            this->m_btn.set_label(num[this->x] + " - Priximo");
            this->x = 1;
            break;
        }
    }

}

//Ativa o tooltip quando passa pelo botão
bool Botoes::on_btn_tooltip(int, int, bool, const Glib::RefPtr<Gtk::Tooltip>&){
    return true;
}   

//Altera o label e imagem do botão toggle button
void Botoes::on_alt_img_button(){
    if(this->m_tog_btn.get_active() == false){
        //Seta imagem ok
        this->m_tog_btn.set_image_from_icon_name("gtk-ok",Gtk::ICON_SIZE_BUTTON);
          this->m_tog_btn.set_label("TRUE");
    }else{
        this->m_tog_btn.set_image_from_icon_name("gtk-close",Gtk::ICON_SIZE_BUTTON);
        this->m_tog_btn.set_label("FALSE");
    }
}

void Botoes::on_hid_button(){
    if(this->m_ck_btn.get_active() == true){
        this->m_btn.set_state(Gtk::STATE_INSENSITIVE);
        this->m_tog_btn.set_state(Gtk::STATE_INSENSITIVE);
       
    }else{
        this->m_btn.set_state(Gtk::STATE_NORMAL);
        this->m_tog_btn.set_state(Gtk::STATE_NORMAL);
    }
}



void Botoes::on_togbtn_alt(){
    if(this->m_rad_btn1.get_active() == true){
        this->m_rad_btn1.set_image_from_icon_name("emblem-ohno",Gtk::ICON_SIZE_DIALOG);
        this->m_rad_btn2.set_image_from_icon_name("emblem-OK",Gtk::ICON_SIZE_DIALOG);
    }else{
        this->m_rad_btn2.set_image_from_icon_name("emblem-ohno",Gtk::ICON_SIZE_DIALOG);
        this->m_rad_btn1.set_image_from_icon_name("emblem-OK",Gtk::ICON_SIZE_DIALOG);
    }
}