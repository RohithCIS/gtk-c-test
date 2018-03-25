#include<stdio.h>
#include<gtk/gtk.h>

	GtkEntry *one;
	GtkEntry *two;
	GtkEntry *thr;
	GtkEntry *fou;
	 
struct acc
{
	GtkEntry *name;
	GtkEntry *usern;
	GtkEntry *accno;
	GtkEntry *pwd;
	GtkEntry *cpwd;
};
struct acc test;


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *windowm;
	 FILE *fp;
	 fp=fopen("test.bin","r");
	 fread(&test,sizeof(test),1,fp);
	 fclose(fp);

 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "binver.glade", NULL);
 
    windowm = GTK_WIDGET(gtk_builder_get_object(builder, "test"));
    gtk_builder_connect_signals(builder, NULL);
 
    one=GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    two=GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    thr=GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    fou=GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    gtk_entry_set_text(one,gtk_entry_get_text(test.usern));
    gtk_entry_set_text(two,gtk_entry_get_text(test.name));
    gtk_entry_set_text(thr,gtk_entry_get_text(test.pwd));
    gtk_entry_set_text(fou,gtk_entry_get_text(test.accno));
    g_object_unref(builder);
    
    gtk_widget_show(windowm);    
    gtk_main();
    
    return 0;
}
void on_window1_destroy()
{
    gtk_main_quit();
}

