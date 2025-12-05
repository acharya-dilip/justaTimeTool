#include <stdio.h>
#include <gtk/gtk.h>

struct windowMain {
    GtkWidget *windowMain;
    GtkWidget *gridParent;
    GtkWidget *buttonStopWatch;
    GtkWidget *buttonWorldClock;
    GtkWidget *buttonPomodoro;
    GtkWidget *buttonTimer;
}windowMain;
static void activate(GtkApplication *app, gpointer user_data) {

    //Init of windowMain
    windowMain.windowMain = gtk_application_window_new(app);
    // gtk_window_set_default_size(GTK_WINDOW(windowMain.windowMain),490,360);
    gtk_window_set_title(GTK_WINDOW(windowMain.windowMain),"JustaTimeTool");
    gtk_window_present(GTK_WINDOW(windowMain.windowMain));

    //Init of gridParent;
    windowMain.gridParent = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowMain.windowMain),windowMain.gridParent);
    //Margins & Paddings
    gtk_widget_set_margin_top(windowMain.gridParent,10);
    gtk_widget_set_margin_bottom(windowMain.gridParent,10);
    gtk_widget_set_margin_start(windowMain.gridParent,10);
    gtk_widget_set_margin_end(windowMain.gridParent,10);
    // gtk_widget_set_halign(windowMain.gridParent,GTK_ALIGN_CENTER);
    // gtk_widget_set_valign(windowMain.gridParent,GTK_ALIGN_CENTER);

    // //Init labelPlaceholder
    // GtkWidget *labelPlaceholder = gtk_label_new("");
    // gtk_grid_attach(GTK_GRID(windowMain.gridParent),labelPlaceholder,0,0,10,1);
    // gtk_widget_set_size_request(GTK_WIDGET(windowMain.windowMain),480,-1);

    //Init of buttonStopWatch
    windowMain.buttonStopWatch = gtk_button_new_with_label("⏱️");
    gtk_grid_attach(GTK_GRID(windowMain.gridParent),windowMain.buttonStopWatch,0,0,1,1);
    gtk_widget_set_size_request(windowMain.buttonStopWatch,160,120);

    //Init of buttonWorldClock
    windowMain.buttonWorldClock = gtk_button_new_with_label("🌐");
    gtk_grid_attach(GTK_GRID(windowMain.gridParent),windowMain.buttonWorldClock,1,0,1,1);
    gtk_widget_set_size_request(windowMain.buttonWorldClock,160,120);


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