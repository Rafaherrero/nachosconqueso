#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

#include "harryPotter.h"

#include <iostream>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::VentanaPrincipal)
{

	mapa_t* el_mapa = new mapa_t(TAMANO_X,TAMANO_Y);
	el_mapa->generar_laberinto();

	harryPotter harry_potter(*el_mapa);

	ui->setupUi(this);
	this->setMaximumSize((TAMANO_X*TAMANO_ICONO)+40,(TAMANO_Y*TAMANO_ICONO)+100);
	scene = new QGraphicsScene(this);
	//scene->setSceneRect(0,0,64,64);
	//ui->grafico_mapa->resize(67,67);
	ui->grafico_mapa->resize(TAMANO_X*TAMANO_ICONO,TAMANO_Y*TAMANO_ICONO);
	ui->grafico_mapa->setScene(scene);
	scene->setSceneRect(0, 0, TAMANO_X*TAMANO_ICONO, TAMANO_Y*TAMANO_ICONO);
	ui->grafico_mapa->setMaximumSize((TAMANO_X*TAMANO_ICONO)+3,(TAMANO_Y*TAMANO_ICONO)+3);

	QImage image_seto(RUTA_SETO);
	QImage image_cesped(RUTA_CESPED);
	QImage image_harry(RUTA_HARRY);
	QImage image_copa(RUTA_COPA);
	QImage image_dementor(RUTA_DEMENTOR);
	QImage image_gragea(RUTA_GRAGEA);

	QGraphicsPixmapItem* objeto[TAMANO_X][TAMANO_Y];
	QGraphicsPixmapItem* harry_icono;
	QGraphicsPixmapItem* copa;

	unsigned conti=0;
	unsigned contj=0;
	QPoint posicion_objeto(0,0);

	for (int j=0;(j<TAMANO_Y*TAMANO_ICONO);j=j+TAMANO_ICONO){
		conti=0;
		for (int i=0;(i<TAMANO_X*TAMANO_ICONO);i=i+TAMANO_ICONO){
			QPoint posicion_objeto(conti,contj);
			if (el_mapa->get_seto(posicion_objeto)){
				objeto[conti][contj] = new QGraphicsPixmapItem(QPixmap::fromImage(image_seto));
				objeto[conti][contj]-> setOffset(i,j);
				scene->addItem(objeto[conti][contj]);
				conti++;
			}
			else{
				objeto[conti][contj] = new QGraphicsPixmapItem(QPixmap::fromImage(image_cesped));
				objeto[conti][contj]-> setOffset(i,j);
				scene->addItem(objeto[conti][contj]);
				conti++;
			}
		}
		contj++;
	}

	harry_icono = new QGraphicsPixmapItem(QPixmap::fromImage(image_harry));
	harry_icono->setOffset(harry_potter.get_posicion_harry().x()*TAMANO_ICONO, harry_potter.get_posicion_harry().y()*TAMANO_ICONO);
	scene->addItem(harry_icono);

	copa = new QGraphicsPixmapItem(QPixmap::fromImage(image_copa));
	std::cout << "La copa está en: " << el_mapa->get_pos_copa().x() << ", " << el_mapa->get_pos_copa().y() << std::endl;
	copa ->setOffset(el_mapa->get_pos_copa().x()*TAMANO_ICONO, el_mapa->get_pos_copa().y()*TAMANO_ICONO);
	scene->addItem(copa);

	ui->estado_harry->setText("Harry ha entrado al laberinto");
	ui->estado_harry->adjustSize();

}

void VentanaPrincipal::set_texto_estado(QString estado_harry){
	ui->estado_harry->setText(estado_harry);
	ui->estado_harry->adjustSize();
}

VentanaPrincipal::~VentanaPrincipal()
{
	delete ui;
}
