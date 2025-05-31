#include "interfaz.h"

GtkDropDown *structure_type;
GtkEntry *input_entry, *pos_entry;
GtkTextView *output_view;
GtkWidget *push_btn, *pop_btn, *enqueue_btn, *dequeue_btn;
GtkWidget *insert_front_btn, *insert_end_btn;
GtkWidget *remove_front_btn, *remove_end_btn;
GtkWidget *insert_at_pos_btn, *remove_at_pos_btn, *remove_by_data_btn;
GtkWidget *search_at_pos_btn, *search_by_data_btn;
GtkWidget *add_struct_btn, *remove_struct_btn;
GtkDrawingArea *drawing_area;
GList *structure_data_list = NULL;

const char *get_type_name(int type) {
    static const char *names[] = {
        "Pila", "ColaSimple", "ColaCircular", "Bicola",
        "ListaSimple", "ListaCircular", "ListaDoble", "ListaDobleCircular"
    };
    return (type >= 0 && type < NUM_STRUCTURE_TYPES) ? names[type] : "Desconocido";
}

void on_add_structure_clicked(GtkButton *button, gpointer user_data) {
    // Obtener el tipo seleccionado del dropdown
    int selected_type = gtk_drop_down_get_selected(structure_type);
    
    // Crear una nueva estructura
    StructureData *new_struct = g_malloc(sizeof(StructureData));
    new_struct->type = selected_type;
    new_struct->name = g_strdup(get_type_name(selected_type));
    
    // Inicializar la estructura de datos según el tipo
    switch (selected_type) {
        case 0:  // Pila
            // Ejemplo de como crear una pila: funcion, void* create_stack(), modificar segun su codigo
            //new_struct->list = create_stack(); // esta función retorna un apuntador tipo void aunque dentro crea una pila
            break;        
        // TODO: Completar los casos para las demas estructuras
        default:
            new_struct->list = NULL;
            break;
    }
    
    // Agregar a la lista global de estructuras
    structure_data_list = g_list_append(structure_data_list, new_struct);
    
    // Actualizar la interfaz
    update_output(g_strdup_printf("Nueva %s creada", new_struct->name));
    
    // Opcional: Seleccionar automáticamente la nueva estructura
    gtk_drop_down_set_selected(structure_type, g_list_length(structure_data_list) - 1);
}

void on_remove_structure_clicked(GtkButton *button, gpointer user_data) {    
    
    StructureData *sd = get_current_structure();    
    
    // Inicializar la estructura de datos según el tipo
    switch (sd->type) {
        case 0:  // Pila
            //TODO: Llamar de forma correcta a la función que borre a la pila
            //free_stack((Stack*)sd);
            break;        
        // TODO: Completar los casos para las demas estructuras
        default:            
            break;
    }
    
    // Agregar a la lista global de estructuras
    structure_data_list = g_list_delete_link(structure_data_list, sd);
    
    // Actualizar la interfaz
    update_output(g_strdup_printf("Se borro estructura creada"));    
    
}

void update_output(const gchar *message) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(output_view);
    gtk_text_buffer_set_text(buffer, message, -1);
}

StructureData *get_current_structure() {
    int index = gtk_drop_down_get_selected(structure_type);
    return g_list_nth_data(structure_data_list, index);
}

void on_structure_type_changed(GtkDropDown *dropdown, GParamSpec *pspec, gpointer user_data) {
    int index = gtk_drop_down_get_selected(dropdown);

    gtk_widget_set_visible(push_btn, FALSE);
    gtk_widget_set_visible(pop_btn, FALSE);
    gtk_widget_set_visible(enqueue_btn, FALSE);
    gtk_widget_set_visible(dequeue_btn, FALSE);
    gtk_widget_set_visible(insert_front_btn, FALSE);
    gtk_widget_set_visible(insert_end_btn, FALSE);
    gtk_widget_set_visible(insert_at_pos_btn, FALSE);
    gtk_widget_set_visible(remove_front_btn, FALSE);
    gtk_widget_set_visible(remove_end_btn, FALSE);    
    gtk_widget_set_visible(remove_by_data_btn, FALSE);
    gtk_widget_set_visible(remove_at_pos_btn, FALSE);
    gtk_widget_set_visible(search_at_pos_btn, FALSE);
    gtk_widget_set_visible(search_by_data_btn, FALSE);

    switch (index) {
        case 0:
            gtk_widget_set_visible(push_btn, TRUE);
            gtk_widget_set_visible(pop_btn, TRUE);
            break;
        case 1: case 2:
            gtk_widget_set_visible(enqueue_btn, TRUE);
            gtk_widget_set_visible(dequeue_btn, TRUE);
            break;
        case 3:
            gtk_widget_set_visible(enqueue_btn, TRUE);
            gtk_widget_set_visible(dequeue_btn, TRUE);
            gtk_widget_set_visible(insert_front_btn, TRUE);
            gtk_widget_set_visible(insert_end_btn, TRUE);
            gtk_widget_set_visible(remove_front_btn, TRUE);
            gtk_widget_set_visible(remove_end_btn, TRUE);
            break;
        case 4: case 5: case 6: case 7:
            gtk_widget_set_visible(insert_front_btn, TRUE);
            gtk_widget_set_visible(insert_end_btn, TRUE);
            gtk_widget_set_visible(insert_at_pos_btn, TRUE);
            //gtk_widget_set_visible(insert_by_data_btn, TRUE);
            gtk_widget_set_visible(remove_front_btn, TRUE);
            gtk_widget_set_visible(remove_end_btn, TRUE);
            gtk_widget_set_visible(remove_by_data_btn, TRUE);
            gtk_widget_set_visible(remove_at_pos_btn, TRUE);
            gtk_widget_set_visible(search_at_pos_btn, TRUE);
            gtk_widget_set_visible(search_by_data_btn, TRUE);
            //gtk_widget_set_visible(search_btn, TRUE);
            break;
    }

    StructureData *sd = get_current_structure();
    if (sd)
        update_output(sd->name);
}

void on_push_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));
    if (strlen(text) > 0) {
        //TODO: Agregar el código para hacer push en la pila sd        
        update_output("Elemento insertado en pila");
    }
}

void on_pop_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    if (sd->list != NULL) {
        //gchar *data = (List*) sd->lista->head->data; // Se hace cast para convertir de (void*) a List*
        //TODO: Llamar a la función pop de la pila
        //update_output(data); 
        //g_free(data);
    } else {
        update_output("Pila vacía");
    }
}

void on_enqueue_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));

    if (strlen(text) > 0) {
        //TODO: Llamar a la función para encolar
        update_output("Elemento encolado");
    }
}

void on_dequeue_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    if (sd->list != NULL) {        
        //TODO: Obtener la informacion del nodo a desencolar, usando gchar*
        //TODO: Llamar a la función para desencolar
        //update_output(data); //Descomentar despues de realizar TODO(9)
        //g_free(data); //Descomentar despues de realizar TODO(9)
    } else {
        update_output("Cola vacía");
    }
}

void on_insert_front_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));

    if (strlen(text) > 0) {
        //TODO: Llamar a la función para insertar al inicio, recuerda validar si es una estructura doblemente ligada
        update_output("Elemento insertado");
    }
}

void on_insert_end_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));

    if (strlen(text) > 0) {
        //TODO: Llamar a la función para insertar al final, recuerda validar si es una estructura doblemente ligada
        update_output("Elemento insertado");
    }
}

void on_insert_at_pos_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));
    const gchar *pos_text = gtk_editable_get_text(GTK_EDITABLE(input_entry));
    int pos;
    char *endptr;
    if(strlen(pos_text)>0){
        pos = (int)g_ascii_strtoll(pos_text, &endptr, 10);
        if(*endptr !='\0'){
            update_output("Error la cadena no es una posición válida\n");
            return;
        }
        if (strlen(text) > 0) {
            //TODO: Llamar a la función para insertar por posición, recuerda validar si es una estructura doblemente ligada
            update_output("Elemento insertado");
        }
    }
}


void on_remove_front_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    
    if (sd->list != NULL) {
        //TODO: Llamar a la función para eliminar al inicio, recuerda validar si es una estructura doblemente ligada
        update_output("Elemento eliminado");
    }
}

void on_remove_end_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();    

    if (sd->list != NULL) {
        //TODO: Llamar a la función para eliminar al final, recuerda validar si es una estructura doblemente ligada
        update_output("Elemento eliminado");
    }
}

void on_remove_at_pos_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();    
    const gchar *pos_text = gtk_editable_get_text(GTK_EDITABLE(input_entry));
    int pos;
    char *endptr;
    if(strlen(pos_text)>0){
        pos = (int)g_ascii_strtoll(pos_text, &endptr, 10);
        if(*endptr !='\0'){
            update_output("Error la cadena no es una posición válida\n");
            return;
        }
        if (sd->list != NULL){
            //TODO: Llamar a la función para eliminar por posición, recuerda validar si es una estructura doblemente ligada
            update_output("Elemento eliminado");
        }
    }
}

void on_remove_by_data_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));

    if (strlen(text) > 0 && sd->list != NULL) {
        //TODO: Llamar a la función para eliminar por dato, recuerda validar si es una estructura doblemente ligada
        update_output("Elemento eliminado");
    }
}

void on_search_at_pos_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();    
    const gchar *pos_text = gtk_editable_get_text(GTK_EDITABLE(input_entry));
    int pos;
    char *endptr;
    if(strlen(pos_text)>0){
        pos = (int)g_ascii_strtoll(pos_text, &endptr, 10);
        if(*endptr !='\0'){
            update_output("Error la cadena no es una posición válida\n");
            return;
        }
        if (sd->list != NULL){
            //TODO: Llamar a la función para buscar por posición, recuerda validar si es una estructura doblemente ligada
            //TODO: Estructura if para determinar si se encontro o no el dato
            update_output("Elemento eliminado");
        }
    }
}

void on_search_by_data_clicked(GtkButton *button, gpointer user_data) {
    StructureData *sd = get_current_structure();
    const gchar *text = gtk_editable_get_text(GTK_EDITABLE(input_entry));

    if (strlen(text) > 0 && sd->list != NULL) {
        //TODO: Llamar a la función para buscar por dato, recuerda validar si es una estructura doblemente ligada
        //TODO: Estructura if para determinar si se encontro o no el dato
        update_output("Elemento encontrado");
    }
}


gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    StructureData *sd = get_current_structure();

    //TODO: Obtener el primer nodo y llamarlo current
    int x= 20, y = 50;
    int box_width = 60, box_height = 40;
    int spacing = 30;

    //TODO: Modificar o agregar código para dibujar las estructuras circulares
    //TODO: Quitar el comentario despues de declarar current
    /*while(current){
        cairo_rectangle(cr, x, y, box_width, box_height);
        cairo_set_source_rgb(cr, 0.8, 0.9, 1.0);
        cairo_fill_preserve(cr);
        cairo_set_source_rgb(cr, 0,0,0);
        cairo_stroke(cr);

        cairo_move_to(cr, x+10, y+25);
        cairo_set_font_size(cr, 12);
        cairo_show_text(cr, (char*)current->data);

        // Dibuja la flecha al siguiente nodo
        if (current->next) {
            int arrow_start_x = x + box_width;
            int arrow_end_x = x + box_width + spacing;
            int arrow_y = y + box_height / 2;

            cairo_move_to(cr, arrow_start_x, arrow_y);
            cairo_line_to(cr, arrow_end_x, arrow_y);
            cairo_stroke(cr);

            // flecha
            cairo_move_to(cr, arrow_end_x - 5, arrow_y - 5);
            cairo_line_to(cr, arrow_end_x, arrow_y);
            cairo_line_to(cr, arrow_end_x - 5, arrow_y + 5);
            cairo_stroke(cr);
        } else {
            // Dibuja NULL
            cairo_move_to(cr, x + box_width + 5, y + 25);
            cairo_show_text(cr, "NULL");
        }

        x += box_width + spacing;
        current = current->next;
    }*/

    return FALSE;
}

void application_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new_from_file("interfaz.ui");
    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    gtk_window_set_application(GTK_WINDOW(window), app);

    // Se asocian los elementos visuales a su respectivo componente de código
    structure_type = GTK_DROP_DOWN(gtk_builder_get_object(builder, "structure_type_combo"));
    input_entry = GTK_ENTRY(gtk_builder_get_object(builder, "input_entry"));
    pos_entry = GTK_ENTRY(gtk_builder_get_object(builder, "position_entry"));
    output_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "output_view"));
    push_btn = GTK_WIDGET(gtk_builder_get_object(builder, "push_btn"));
    pop_btn = GTK_WIDGET(gtk_builder_get_object(builder, "pop_btn"));
    enqueue_btn = GTK_WIDGET(gtk_builder_get_object(builder, "enqueue_btn"));
    dequeue_btn = GTK_WIDGET(gtk_builder_get_object(builder, "dequeue_btn"));
    insert_front_btn = GTK_WIDGET(gtk_builder_get_object(builder, "insert_front_btn"));
    insert_end_btn = GTK_WIDGET(gtk_builder_get_object(builder, "insert_end_btn"));
    remove_front_btn = GTK_WIDGET(gtk_builder_get_object(builder, "remove_front_btn"));
    remove_end_btn = GTK_WIDGET(gtk_builder_get_object(builder, "remove_end_btn"));
    search_by_data_btn = GTK_WIDGET(gtk_builder_get_object(builder, "search_by_data_btn"));
    search_at_pos_btn = GTK_WIDGET(gtk_builder_get_object(builder, "search_at_position_btn"));
    insert_at_pos_btn = GTK_WIDGET(gtk_builder_get_object(builder, "insert_at_position_btn"));
    remove_at_pos_btn = GTK_WIDGET(gtk_builder_get_object(builder, "remove_at_position_btn"));
    remove_by_data_btn = GTK_WIDGET(gtk_builder_get_object(builder, "remove_by_data_btn"));
    drawing_area = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "drawing_area"));
    add_struct_btn = GTK_WIDGET(gtk_builder_get_object(builder, "add_structure_btn"));
    remove_struct_btn = GTK_WIDGET(gtk_builder_get_object(builder, "remove_structure_btn"));
    
    gtk_widget_set_visible(push_btn, TRUE);
    gtk_widget_set_visible(pop_btn, TRUE);
    gtk_widget_set_visible(enqueue_btn, FALSE);
    gtk_widget_set_visible(dequeue_btn, FALSE);
    gtk_widget_set_visible(insert_front_btn, FALSE);
    gtk_widget_set_visible(insert_end_btn, FALSE);
    gtk_widget_set_visible(insert_at_pos_btn, FALSE);
    gtk_widget_set_visible(remove_front_btn, FALSE);
    gtk_widget_set_visible(remove_end_btn, FALSE);    
    gtk_widget_set_visible(remove_by_data_btn, FALSE);
    gtk_widget_set_visible(remove_at_pos_btn, FALSE);
    gtk_widget_set_visible(search_at_pos_btn, FALSE);
    gtk_widget_set_visible(search_by_data_btn, FALSE);

    // Se asocian las funciones que responden al clic de los botones
    g_signal_connect(structure_type, "notify::selected", G_CALLBACK(on_structure_type_changed), NULL);
    g_signal_connect(push_btn, "clicked", G_CALLBACK(on_push_clicked), NULL);
    g_signal_connect(pop_btn, "clicked", G_CALLBACK(on_pop_clicked), NULL);
    g_signal_connect(enqueue_btn, "clicked", G_CALLBACK(on_enqueue_clicked), NULL);
    g_signal_connect(dequeue_btn, "clicked", G_CALLBACK(on_dequeue_clicked), NULL);
    g_signal_connect(insert_front_btn, "clicked", G_CALLBACK(on_insert_front_clicked), NULL);
    g_signal_connect(insert_end_btn, "clicked", G_CALLBACK(on_insert_end_clicked), NULL);
    g_signal_connect(insert_at_pos_btn, "clicked", G_CALLBACK(on_insert_at_pos_clicked), NULL);
    g_signal_connect(remove_front_btn, "clicked", G_CALLBACK(on_remove_front_clicked), NULL);
    g_signal_connect(remove_end_btn, "clicked", G_CALLBACK(on_remove_end_clicked), NULL);
    g_signal_connect(remove_at_pos_btn,"clicked", G_CALLBACK(on_remove_at_pos_clicked), NULL);
    g_signal_connect(search_at_pos_btn,"clicked", G_CALLBACK(on_search_at_pos_clicked), NULL);
    g_signal_connect(search_by_data_btn,"clicked", G_CALLBACK(on_search_by_data_clicked), NULL);
    g_signal_connect(add_struct_btn,"clicked", G_CALLBACK(on_add_structure_clicked), NULL);
    g_signal_connect(remove_struct_btn,"clicked", G_CALLBACK(on_remove_structure_clicked), NULL);

    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);

    gtk_window_present(window);    
}