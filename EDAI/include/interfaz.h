// TODO: Agregar el #ifndef
#ifndef INTERFAZ_H_
// TODO: Agregar el #define
#define INTERFAZ_H_
#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// TODO: Aquí se debe incluir el archivo en donde se define la estructura lista ligada
// TODO: Aquí se debe incluir el archivo en donde se define la estructura doblemente ligada

#define NUM_STRUCTURE_TYPES 8


typedef struct {
    char *name;
    int type;
    /*
     * AQUI SE APUNTA A CUALQUIER TIPO DE ESTRUCTURA POR ESO ES TIPO VOID, PARA QUE SE PUEDA HACER CAST
    */
    void *list; 
} StructureData;

const char *get_type_name(int type);

void update_output(const gchar *message) ;

StructureData *get_current_structure();

void on_dropdown_bind(GtkSignalListItemFactory *factory, GtkListItem *list_item, gpointer user_data) ;

void on_structure_type_changed(GtkDropDown *dropdown, GParamSpec *pspec, gpointer user_data);

    

void on_push_clicked(GtkButton *button, gpointer user_data);

void on_pop_clicked(GtkButton *button, gpointer user_data) ;

void on_enqueue_clicked(GtkButton *button, gpointer user_data) ;

void on_dequeue_clicked(GtkButton *button, gpointer user_data) ;

gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data);

void application_activate(GtkApplication *app, gpointer user_data) ;


// TODO(3): Cerrar el #ifndef
#endif