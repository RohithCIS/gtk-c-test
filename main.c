#include <gtk/gtk.h>
#include <stdio.h>
 
     GtkWidget      *login_btn;
     GtkWidget		*cnew_btn;
     GtkEntry       *username;
     GtkLabel       *welcome;
     GtkWidget		*crnew_btn;

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
    GtkWidget       *window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "window_main.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
 
    login_btn=GTK_WIDGET(gtk_builder_get_object(builder,"login"));
    cnew_btn=GTK_WIDGET(gtk_builder_get_object(builder,"cnew"));
    username=GTK_ENTRY(gtk_builder_get_object(builder,"username"));
    g_object_unref(builder);
    
    gtk_widget_show(window);    
    gtk_main();
    
    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}

void on_login_clicked(int argc, char *argv[])
{
    GtkBuilder      *builder; 
	GtkWidget       *window_home;
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "home.glade", NULL);
    
    window_home = GTK_WIDGET(gtk_builder_get_object(builder, "home"));
    gtk_builder_connect_signals(builder, NULL);
    
    welcome=GTK_LABEL(gtk_builder_get_object(builder,"user_wlabel"));
    gtk_label_set_text(welcome,gtk_entry_get_text(username));
    g_object_unref(builder); 
	gtk_widget_show(window_home);
	gtk_main();
	
}

void on_home_destroy()
{
	gtk_main_quit();
}

void on_cnew_clicked(int argc, char *argv[])
{
	GtkBuilder      *builder; 
	GtkWidget       *cnew;
	GtkEntry		*name;
	GtkEntry		*uname;
	GtkEntry		*pwd;
	GtkEntry		*cpwd;

	
	gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
	gtk_builder_add_from_file (builder, "cnew.glade", NULL);
    
 	cnew = GTK_WIDGET(gtk_builder_get_object(builder, "cnew"));
 	crnew_btn=GTK_WIDGET(gtk_builder_get_object(builder, "crnew"));
    gtk_builder_connect_signals(builder, NULL);
    
    name=GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
    uname=GTK_ENTRY(gtk_builder_get_object(builder, "entry2"));
    pwd=GTK_ENTRY(gtk_builder_get_object(builder, "entry3"));
    cpwd=GTK_ENTRY(gtk_builder_get_object(builder, "entry4"));
    //if((char*)gtk_entry_get_text(pwd)==(char*)gtk_entry_get_text(cpwd))
    //{
    	test.name=(name);
		test.usern=(uname);
    	test.pwd=(pwd);
    	test.cpwd=(cpwd);
    	
    //}
    
    g_object_unref(builder); 
	gtk_widget_show(cnew);
	gtk_main();
}

void on_crnew_clicked(int argc, char *argv[])
{
	GtkBuilder      *builder; 
	//GtkWidget       *pwdinv;
	FILE *p;
	p=fopen("test.bin","a");
	fwrite(&test,sizeof(test),1,p);
	fclose(p);
	gtk_init(&argc, &argv);
	 
		builder = gtk_builder_new();
		gtk_builder_add_from_file (builder, "cnew.glade", NULL);
		 
	 	//pwdinv = GTK_WIDGET(gtk_builder_get_object(builder, "pwdinv"));
		gtk_builder_connect_signals(builder, NULL);
		g_object_unref(builder); 
	//	gtk_widget_show(pwdinv);
		gtk_main();
	
}
