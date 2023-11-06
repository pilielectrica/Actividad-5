#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
///Punto de entrada a la aplicación///
using namespace std;

Sprite cursor;
Texture cursortexture;
Text mensaje;
Font font;

int main() {
	Event evt; 

	font.loadFromFile("SIXTY.TTF");
	cursor.setScale(0.1, 0.1);
	mensaje.setFont(font);
	mensaje.setString("Presiona los siguientes numeros para cambiar el tamaño de\n la ventana. La resolucion actual es de 600 x 600\n1:800x600\n2:848x480\n3:960x540");
	mensaje.setCharacterSize(24);
	mensaje.setFillColor(Color::White);
	mensaje.setPosition(40, 50);

	cursortexture.loadFromFile("cursor.png");
	cursor.setTexture(cursortexture);

	sf::RenderWindow App(sf::VideoMode(600, 600, 32),
		"Que ventana horrible");
	App.setMouseCursorVisible(false);

	// Loop principal
	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::MouseMoved:
				/////Actualizamos la posición del sprite con/////
				/////la informacion del evento del mouse/////
				cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);

			case Event::KeyPressed:
				if ((Keyboard::isKeyPressed(Keyboard::Num1) == true))
				{

					App.setSize(Vector2u(800, 600));
				}

				if ((Keyboard::isKeyPressed(Keyboard::Num2) == true))
				{
					App.setSize(Vector2u(848, 480));
				}
				if ((Keyboard::isKeyPressed(Keyboard::Num3) == true))
				{
					App.setSize(Vector2u(960, 540));
				}

			}
		}

		App.clear();

		App.draw(cursor);
		App.draw(mensaje);
		// Mostramos la ventana
		App.display();
	}

	return 0;
}
