
//Se carga una imagen de disco y se muestra por pantalla
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#define IMAGEN "./imagenes/ivvi.jpg"

int main()
{
	// Variables
	//Nombre de la imagen que se va a cargar
	char NombreImagen[] = IMAGEN;
	Mat imagen;
	
	//Se carga la imagen desde disco y se comprueba que lo ha hecho correctamente
	imagen = imread(NombreImagen);
	if( !imagen.data ) { 
		cout<< "Error al cargar la imagen: " << NombreImagen <<endl;
		exit(1);
	}

	//Mostrar la imagen
	// Se crea un lienzo donde mostrar imagenes
	// Se asocia la imagen con el lienzo

	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", imagen );
		
	// Se muestra la imagen un tiemp omedido en ms.
	// 0 significa que se espera hasta pulsar un tecla
	waitKey(0);
	
	return 0;
}
