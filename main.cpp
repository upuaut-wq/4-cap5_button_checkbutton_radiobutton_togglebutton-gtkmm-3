#include <gtkmm/application.h>
#include "botoes.h"

int main(int argc, char * argv[]){
    auto app = Gtk::Application::create(argc, argv, "cap5.buttons");
    Botoes btn;
    app->run(btn);
}