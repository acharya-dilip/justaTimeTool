#include <stdio.h>
#include <gtk/gtk.h>

struct windowMain {
    GtkWidget *windowMain;
    GtkWidget *gridParent;
}windowMain;
static void activate(GtkApplication *app, gpointer user_data) {

    //Init of windowMain
    windowMain.windowMain = gtk_application_window_new(app);
    gtk_window_set_default_size(GTK_WINDOW(windowMain.windowMain),400,400);
    gtk_window_set_title(GTK_WINDOW(windowMain.windowMain),"JustaTimeTool");
    gtk_window_present(GTK_WINDOW(windowMain.windowMain));

    //Init of gridParent;
    windowMain.gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowMain.windowMain),windowMain.gridParent);


}


int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}