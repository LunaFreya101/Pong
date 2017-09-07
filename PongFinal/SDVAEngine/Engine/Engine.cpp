#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	int score1 = 0;
	int score2 = 0;
	
	const int PaddleWidth = 20;
	const int PaddleHeight = 100;

	const int WindowWidth = 1024;
	const int WindowHeight = 512;

	bool BallVisible = true;

	sf::Vector2f velocity;
	velocity.x = 0;
	velocity.y = 0;

	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Welcome to SDVA 203!");

	sf::RectangleShape paddle(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle.setFillColor(sf::Color::Blue);
	paddle.setPosition(0 + 40, 512 / 2);

	sf::RectangleShape paddle2(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle2.setFillColor(sf::Color::Red);
	paddle2.setPosition(WindowWidth - PaddleWidth - 40, 512 / 2);

	sf::RectangleShape paddle3(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle3.setFillColor(sf::Color::Yellow);
	paddle3.setPosition(WindowWidth - PaddleWidth - 700, 512 / 5);

	sf::RectangleShape paddle4(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle4.setFillColor(sf::Color::Green);
	paddle4.setPosition(WindowWidth - PaddleWidth - 300, 512 / 5);

	sf::RectangleShape paddle5(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle5.setFillColor(sf::Color::Cyan);
	paddle5.setPosition(WindowWidth - PaddleWidth - 700, 512 / 2 + 100);

	sf::RectangleShape paddle6(sf::Vector2f(PaddleWidth, PaddleHeight));
	paddle6.setFillColor(sf::Color::Magenta);
	paddle6.setPosition(WindowWidth - PaddleWidth - 300, 512 / 2 + 100);

	sf::CircleShape Ball(15.0f);
	Ball.setFillColor(sf::Color::Magenta);
	Ball.setPosition(1024 / 2 , 512 / 2);
	Ball.setOrigin(15, 15);

	const float PI = 3.1415926535897932384626433832795;
	const float degreesToRadians = 2 * PI / 360.0f;
	float angleInRadians = 45 * degreesToRadians;
	float speed = 100.0f;
	float acceleration = 600.0f;
	
	
	sf::Clock clock;

	sf::Font myfont;
	myfont.loadFromFile("Fonts/Punktype.ttf");
	
	sf::Text goal1;
	goal1.setFont(myfont);
	goal1.setCharacterSize(50);
	goal1.setPosition(256, 5);

	sf::Text goal2;
	goal2.setFont(myfont);
	goal2.setCharacterSize(50);
	goal2.setPosition(256 * 3, 5);

	sf::Text p1Wins;
	p1Wins.setFont(myfont);
	p1Wins.setCharacterSize(50);
	p1Wins.setPosition(1024 / 2, 512 / 2);

	sf::Text p2Wins;
	p2Wins.setFont(myfont);
	p2Wins.setCharacterSize(50);
	p2Wins.setPosition(1024 / 2, 512 / 2);

	sf::SoundBuffer JumpBuffer;
	if (!JumpBuffer.loadFromFile("Audio/Jump.wav"))
	{
		return 1;
	}
	sf::Sound JumpSound;
	JumpSound.setBuffer(JumpBuffer);
	
	sf::Music music;
	if (!music.openFromFile("Audio/with-u_-Lonely.ogg"))
	{
		return 1;
	}
	music.setLoop(true);
	music.play();

	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				JumpSound.play();
			}
		}
		
		if (event.key.code == sf::Keyboard::Space)
		{
			velocity.x = 200;
			velocity.y = -200;
		}
	
		//ball collison with the paddle
		sf::Vector2f BallPos = Ball.getPosition();
		float radius = Ball.getRadius();

		if(BallPos.x + radius> paddle.getPosition().x &&
			BallPos.x  - radius < paddle.getPosition().x + paddle.getSize().x &&
			BallPos.y  + radius > paddle.getPosition().y &&
			BallPos.y  - radius < paddle.getPosition().y + paddle.getSize().y )
		{
			Ball.setPosition(paddle.getPosition().x + 20 + radius, Ball.getPosition().y);
			velocity.x *= -1.05;
		}
	
		if (BallPos.x + radius > paddle2.getPosition().x &&
		BallPos.x - radius < paddle2.getPosition().x + paddle2.getSize().x &&
		BallPos.y + radius > paddle2.getPosition().y &&
		BallPos.y - radius< paddle2.getPosition().y + paddle2.getSize().y)
		
		{
			Ball.setPosition(paddle2.getPosition().x - radius, Ball.getPosition().y);
			velocity.x *= -1.05;
		}

	if (BallPos.x + radius > paddle3.getPosition().x &&
		BallPos.x - radius < paddle3.getPosition().x + paddle3.getSize().x &&
		BallPos.y + radius > paddle3.getPosition().y &&
		BallPos.y - radius< paddle3.getPosition().y + paddle3.getSize().y)

	{
		if (velocity.x > 0)
		{
			Ball.setPosition(paddle3.getPosition().x - 20 - radius, Ball.getPosition().y);
		}
		else
		{
			Ball.setPosition(paddle3.getPosition().x + 20 + radius, Ball.getPosition().y);
		}

		velocity.x *= -1.05;
	}

	if (BallPos.x + radius > paddle4.getPosition().x &&
		BallPos.x - radius < paddle4.getPosition().x + paddle4.getSize().x &&
		BallPos.y + radius > paddle4.getPosition().y &&
		BallPos.y - radius< paddle4.getPosition().y + paddle4.getSize().y)

	{
		if (velocity.x > 0)
		{
			Ball.setPosition(paddle4.getPosition().x - 20 - radius, Ball.getPosition().y);
		}
		else
		{
			Ball.setPosition(paddle4.getPosition().x + 20 + radius, Ball.getPosition().y);
		}

		velocity.x *= -1.05;
	}

	if (BallPos.x + radius > paddle5.getPosition().x &&
		BallPos.x - radius < paddle5.getPosition().x + paddle5.getSize().x &&
		BallPos.y + radius > paddle5.getPosition().y &&
		BallPos.y - radius< paddle5.getPosition().y + paddle5.getSize().y)

	{
		if (velocity.x > 0)
		{
			Ball.setPosition(paddle5.getPosition().x - 20 - radius, Ball.getPosition().y);
		}
		else
		{
			Ball.setPosition(paddle5.getPosition().x + 20 + radius, Ball.getPosition().y);
		}

		velocity.x *= -1.05;
	}

	if (BallPos.x + radius > paddle6.getPosition().x &&
		BallPos.x - radius < paddle6.getPosition().x + paddle6.getSize().x &&
		BallPos.y + radius > paddle6.getPosition().y &&
		BallPos.y - radius < paddle6.getPosition().y + paddle6.getSize().y)

	{
		if (velocity.x > 0)
		{
			Ball.setPosition(paddle6.getPosition().x - 20 - radius, Ball.getPosition().y);
		}
		else
		{
			Ball.setPosition(paddle6.getPosition().x + 20 + radius, Ball.getPosition().y);
		}
	
		velocity.x *= -1.05;
	}
		
	bool MoveBall = false;
		//paddle 1 movement & collison
		if (sf::Keyboard::isKeyPressed (sf::Keyboard::W))
		{
			paddle.move(0, -1000 * deltaTime.asSeconds());
			MoveBall = true;
			printf("Up");
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			paddle.move(0,  1000 * deltaTime.asSeconds());
			MoveBall = true;
		}

		// Paddle collison
		if (paddle.getPosition().y < 0)
		{
			paddle.setPosition(paddle.getPosition().x, 0.0f);
		}

		if (paddle.getPosition().y + 100 > 512)
		{
			paddle.setPosition(paddle.getPosition().x, 512 - 100);
		}

		//paddle 2 movement 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			paddle2.move(0, -1000 * deltaTime.asSeconds());
			MoveBall = true;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			paddle2.move(0, 1000 * deltaTime.asSeconds());
			MoveBall = true;
		}

		if (MoveBall && velocity.x == 0 && velocity.y == 0)
		{
			velocity.x = 200;
			velocity.y = -150;
		}
		
		//collision
		if (paddle2.getPosition().y < 0)
		{
			paddle2.setPosition(paddle2.getPosition().x, 0.0f);
		}

		if (paddle2.getPosition().y + 100 > 512)
		{
			paddle2.setPosition(paddle2.getPosition().x, 512 - 100);
		}
		
		// ball collison
		if (Ball.getPosition().y < Ball.getRadius())
		{
			Ball.setPosition(Ball.getPosition().x, Ball.getRadius());
			velocity.y *= -1;
			printf("Up");
		}

		else if (Ball.getPosition().y + Ball.getRadius() > 512)
		{
			Ball.setPosition(Ball.getPosition().x, 512 - Ball.getRadius());
			velocity.y *= -1;
			printf("bottom");
		}
		else if (Ball.getPosition().x <= -10 - Ball.getRadius())
		{
			Ball.setPosition(1024 / 2, 512 / 2);
			velocity.x = 0;
			velocity.y = 0;
			score2++;
			//printf("right");
		}

		else if (Ball.getPosition().x + Ball.getRadius() >= 1034 - Ball.getRadius())
		{
			Ball.setPosition(1024 / 2, 512 / 2);
			velocity.x = 0;
			velocity.y = 0;
			score1++;
			//printf("right");
		}

		std::ostringstream p1score;
		p1score << score1;
		goal1.setOrigin(goal1.getGlobalBounds().width / 2, 0);
		goal1.setString(p1score.str());

		std::ostringstream p2score;
		p2score << score2;
		goal2.setOrigin(goal2.getGlobalBounds().width / 2, 0);
		goal2.setString(p2score.str());
		

		if (score1 == 5 || score2 == 5)
		{
			BallVisible = false;
			velocity = sf::Vector2f(0, 0);

			if (score1 == 5)
			{
				window.draw(p1Wins);
			}

			else
			{
				//window.draw(p2Wins);
			}
		}
			
		Ball.move(velocity.x * deltaTime.asSeconds(), velocity.y * deltaTime.asSeconds());
	
		window.clear();
		if (BallVisible)
		{
			window.draw(Ball);
		}
		
		window.draw(paddle);
		window.draw(paddle2);
		window.draw(paddle3);
		window.draw(paddle4);
		window.draw(paddle5);
		window.draw(paddle6);
		window.draw(goal1);
		window.draw(goal2);

		window.display();
	}

	return 0;
}