//Se cargan imagenes desde un video y se muestran por pantalla
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std; 

#define TECLA_ESCAPE 27
#define VIDEO "./videos/icab_demo_EPS.mp4"

int main(int argc, char* argv[])
{
	// Variables
	Mat frame;
	VideoCapture capture(VIDEO);
	// tecla presionada
	char pressedKey = 0;
	// Se crea un lienzo donde mostrar imagenes
	namedWindow("video", WINDOW_AUTOSIZE);

	// Carga el video
	//capture.open(VIDEO);
	if (!capture.isOpened()){
		cout << "Error al cargar el video!" << endl;
		return 1;
	}
	else{
		while (pressedKey != TECLA_ESCAPE){
			// Se lee el vidoe imagen a imagen
			//capture >> frame;
			capture.read(frame);
			// Se comprueba que no se ha llegaod al final
			if (frame.empty()) {
				cout << "Se ha llegado al final del video" << endl;
				return 1;
			}
			// Se muestra la imagen
			imshow("video", frame);
			// Se espera 20 ms
			pressedKey = waitKey(20);
		}
	}
}
