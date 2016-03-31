#include <gtk/gtk.h>

int main(int argc, char * argv[])
{
	GtkWidget * fenetre;

	gtk_init(&argc, &argv);
	
	fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(fenetre), 300, 200);
	
	g_signal_connect(G_OBJECT(fenetre), "destroy", G_CALLBACK(gtk_main_quit),NULL);
	
	gtk_widget_show_all(fenetre);

	gtk_main();
}