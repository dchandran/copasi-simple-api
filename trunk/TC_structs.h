 /**
  * @file    TC_structs.h
  * @brief   Additional structures and methods used with the Simple C API

 */

#ifndef TINKERCELL_CSTRUCTS_H
#define TINKERCELL_CSTRUCTS_H

#ifndef BEGIN_C_DECLS
#ifdef __cplusplus
#        define BEGIN_C_DECLS extern "C" {
#        define END_C_DECLS }
#   else
#        define BEGIN_C_DECLS
#        define END_C_DECLS
#endif
#endif

# ifndef TCAPIEXPORT
#  if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#    if defined(STATIC_LINKED)
#          define TCAPIEXPORT
#    else
#   if defined(TC_EXPORTS) || defined(tinkercellapi_EXPORTS)
#              if defined(USE_STDCALL)
#                   define TCAPIEXPORT __stdcall __declspec(dllexport)
#              else
#                   define TCAPIEXPORT __declspec(dllexport)
#              endif
#          else
#              define TCAPIEXPORT
#          endif
#     endif
#  else
#    if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#      define TCAPIEXPORT __attribute__ ((visibility("default")))
#    else
#      define TCAPIEXPORT
#    endif
#  endif
# endif //TCAPIEXPORT

BEGIN_C_DECLS

/*!\brief An array of strings with length information. Use tc_getString(M,i) to get the i-th string*/
typedef struct
{
	int length;
	char ** strings;
} tc_strings;

/*!\brief A 2D table of doubles with row and column names. 
Use tc_getMatrixValue(M,i,j) to get the i,j-th value in tc_matrix M

Use tc_setMatrixValue(M,i,j,value) to set a value */
typedef struct
{
	int rows;            /*!< Number of rows in the matrix */
	int cols;            /*!< Number of columns in the matrix */
	double * values;     /*!< Pointer to the values contained in the matrix */
	tc_strings rownames; /*!< Pointer to list of row labels */
	tc_strings colnames; /*!< Pointer to list of column labels */
} tc_matrix;


/*!\brief Create a matrix with the given number of rows and columns
 \param int number of rows
 \param int number of columns
 \return tc_matrix
 \ingroup Basic
*/
TCAPIEXPORT tc_matrix tc_createMatrix(int rows, int cols);


/*!\brief Create an array of strings
 \param int length
 \return tc_strings
 \ingroup Basic
*/
TCAPIEXPORT tc_strings tc_createStringsArray(int len);


/*!\brief Get i,jth value from a tc_matrix
 \param tc_matrix matrix
 \param int row
 \param int column
 \return double value at the given row, column
 
 Use tc_setMatrixValue(M,i,j,value) to set a value

 \ingroup Basic
*/
TCAPIEXPORT double tc_getMatrixValue(tc_matrix M, int i, int j);


/*!\brief Set i,jth value of a tc_matrix
 \param tc_matrix matrix
 \param int row
 \param int column
 \param double value at the given row, column
 \ingroup Basic
*/
TCAPIEXPORT void tc_setMatrixValue(tc_matrix M, int i, int j, double d);


/*!\brief Get ith row name from a tc_matrix
 \param tc_matrix matrix
 \param int row
 \return string row name
 \ingroup Basic
*/
TCAPIEXPORT const char * tc_getRowName(tc_matrix M, int i);


/*!\brief Set ith row name for a tc_matrix
 \param tc_matrix matrix
 \param int row
 \param string row name
 \ingroup Basic
*/
TCAPIEXPORT void tc_setRowName(tc_matrix M, int i, const char * s);


/*!\brief Get jth column name of a tc_matrix
 \param tc_matrix matrix
 \param int column
 \return string column name
 \ingroup Basic
*/
TCAPIEXPORT const char * tc_getColumnName(tc_matrix M, int j);


/*!\brief Set jth column name of a tc_matrix
 \param tc_matrix matrix
 \param int column
 \param string column name
 \ingroup Basic
*/
TCAPIEXPORT void tc_setColumnName(tc_matrix M, int j, const char * s);

/*!\brief Get ith string in array of strings
 \param tc_strings array
 \param int index
 \return string value
 \ingroup Basic
*/
TCAPIEXPORT const char* tc_getString(tc_strings S, int i);


/*!\brief Set ith string in array of strings
 \param tc_strings array
 \param int index
 \param string value
 \ingroup Basic
*/
TCAPIEXPORT void tc_setString(tc_strings S, int i, const char * c);

/*!\brief Get the index of a string in the array
 \param tc_strings array
 \param char* a string in the array
 \return int index of that string
 \ingroup Basic
*/
TCAPIEXPORT int tc_getStringIndex(tc_strings A, const char * s);


/*!\brief get the row number of a row name
 \param tc_matrix matrix
 \param char* a string in the matrix
 \return int index of that string
 \ingroup Basic
*/
TCAPIEXPORT int tc_getRowIndex(tc_matrix, const char * s);


/*!\brief Get the column number of a column name
 \param tc_matrix matrix
 \param char* a string in the matrix
 \return int index of that string
 \ingroup Basic
*/
TCAPIEXPORT int tc_getColumnIndex(tc_matrix, const char * s);


/*!\brief Delete a matrix
 \param &tc_matrix pointer to matrix
 \ingroup Basic
*/
TCAPIEXPORT void tc_deleteMatrix(tc_matrix M);


/*!\brief Delete an array of strings
 \param &tc_strings pointer to array
 \ingroup Basic
*/
TCAPIEXPORT void tc_deleteStringsArray(tc_strings C);


/*!\brief Combine two matrices by appending their columns. Row size must be equal for both matrices
 \param tc_matrix first matrix
 \param tc_matrix fsecond matrix
 \return tc_matrix new combined matrix
 \ingroup Basic
*/
TCAPIEXPORT tc_matrix tc_appendColumns(tc_matrix A, tc_matrix B);


/*!\brief Combine two matrices by appending their rows. Column sizes must be equal for both matrices
 \param tc_matrix first matrix
 \param tc_matrix fsecond matrix
 \return tc_matrix new combined matrix
 \ingroup Basic
*/
TCAPIEXPORT tc_matrix tc_appendRows(tc_matrix A, tc_matrix B);


/*!\brief Print a matrix to file
 \param char* file name
 \param tc_matrix
 \ingroup Basic
*/
TCAPIEXPORT void tc_printMatrixToFile(const char* file, tc_matrix M);


/*!\brief Print a matrix to stdout
 \param char* file name
 \param tc_matrix
 \ingroup Basic
*/
TCAPIEXPORT void tc_printOutMatrix(tc_matrix M);


END_C_DECLS
#endif

