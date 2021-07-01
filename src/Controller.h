/** \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayLibros LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales);

/** \brief Listar libros
 *
 * \param path char*
 * \param pArrayLibros LinkedList*
 * \return int
 *
 */
int controller_listarLibros(LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales);

/** \brief Ordenar libros
 *
 * \param path char*
 * \param pArrayLibros LinkedList*
 * \return int
 *
 */
int controller_ordenarLibros(LinkedList* pArrayLibros);

/** \brief Guarda los datos del listado de libros en un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayLibros LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales);

/**
 * \brief Realiza descuentos sobre los precios del listado que cumplen con la condición.
 * \param pArrayLibros LinkedList*
 * \param pArrayEditoriales eEditoriales*
 * \param lengthEditoriales
 * \param flag
 * \return
 */
int controller_realizarDescuentos(LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales,int* flag);
