//Se cargan imagenes desde una camara y se muestran por pantalla
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define TECLA_ESCAPE 27
#define CAMARA_0 0


int main()
{
	// Variables
	Mat frame;
	VideoCapture capture(CAMARA_0);
	// tecla presionada
	char pressedKey = 0;
	// Se crea un lienzo donde mostrar imagenes
	namedWindow("video", WINDOW_AUTOSIZE);

	// comprobar que la camara se ha conectado
	if (!capture.isOpened()){
		cout << "Error al conectarse a la camara!" << endl;
		return 1;
	}
	else {
		while (pressedKey != TECLA_ESCAPE) {
			// Se lee la camara
			//capture >> frame;
			capture.read(frame);
			// Se comprueba que no se ha llegaod al final
			if (frame.empty()) {
				cout << "Problema al ller la iamgen" << endl;
				return 1;
			}
			// Se muestra la imagen
			imshow("video", frame);
			// Se espera 20 ms
			pressedKey = waitKey(20);
		}
	}
}
