#include "CMelodies.h"

#pragma region Public methods

void CMelodies::PlayMelody(EMelodies melody)
{
	switch (melody)
	{
		case EMelodies::Fanfarria:
			melody0();
			break;
		case EMelodies::DogPower:
			melody1();
			break;
		case EMelodies::ThirdPhase:
			melody2();
			break;
		case EMelodies::R2D2:
			melody3();
			break;
		case EMelodies::Ohhh:
			melody4();
			break;
		case EMelodies::Uhoh:
			melody5();
			break;
		case EMelodies::R2D2_2:
			r2D2();
			break;	
		case EMelodies::CloseEncounters:
			closeEncounters();
			break;
		case EMelodies::Ariel:
			ariel();
			break;
		case EMelodies::Uhoh2:
			uhoh();
			break;
		case EMelodies::Squeak:
			squeak();
			break;
		case EMelodies::Waka:
			waka();
			break;
		case EMelodies::Catcall:
			catcall();
			break;
		case EMelodies::Ohhh2:
			ohhh();
			break;
	}
}

#pragma endregion

#pragma region Private methods

void CMelodies::melody0() { // MELODIA_FANFARRIA 0
	tone(m_pin, NOTE_C4, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_G3, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_G3, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_A3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_G3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, 0, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C4, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	delay(10);
}

void CMelodies::melody1() { // MELODIA_PODER_PERRUNO
	tone(m_pin, NOTE_B4, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B4, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B4, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS5, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B4, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS5, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	delay(10);
}

void CMelodies::melody2() {	// MELODIA_ENCUENTROS_3A_FASE
							// Based on http://www.mycontraption.com/sound-effects-with-and-arduino/
	tone(m_pin, NOTE_AS5, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C6, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS4, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_DS5, NOTE_BLANCA); delay(NOTE_BLANCA_PAUSA); noTone(m_pin);
	delay(500);

	tone(m_pin, NOTE_AS4, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C5, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS2, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_DS4, NOTE_BLANCA); delay(NOTE_BLANCA_PAUSA); noTone(m_pin);
	delay(500);

	tone(m_pin, NOTE_AS3, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C4, NOTE_NEGRA); delay(NOTE_NEGRA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS2, NOTE_BLANCA); delay(NOTE_BLANCA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_GS1, NOTE_BLANCA); delay(NOTE_BLANCA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_DS3, NOTE_REDONDA); delay(NOTE_REDONDA_PAUSA); noTone(m_pin);
	delay(10);
}

void CMelodies::melody3() {	// MELODIA_R2D2
							// Based on http://www.mycontraption.com/sound-effects-with-and-arduino/
							//http://dtucker.co.uk/make/arduino-using-my-melodyutils-library-for-r2-d2-style-chirps.html
	tone(m_pin, NOTE_A7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_G7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_E7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_D7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_F7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C8, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_A7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_G7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_E7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_D7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_B7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_F7, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	tone(m_pin, NOTE_C8, NOTE_CORCHEA); delay(NOTE_CORCHEA_PAUSA); noTone(m_pin);
	delay(10);
}

void CMelodies::melody4() { // MELODIA_OHHH
	Glis(NOTE_C6, NOTE_C7, 6);
	Glis(NOTE_C7, NOTE_C6, 5);
	//for (int i=1000; i<2000; i=i*1.02) { tone(m_pin,i,10); };
	//for (int i=2000; i>1000; i=i*.98) { tone(m_pin,i,10); delay(10);};
}

void CMelodies::melody5() { // MELODIA_UHOH
	Glis(NOTE_C6, NOTE_DS6, 6);
	delay(200);
	Glis(NOTE_DS6, NOTE_CS6, 5);
	//for (int i=1000; i<1244; i=i*1.01) { tone(m_pin,i,30); };
	//delay(200);
	//for (int i=1244; i>1108; i=i*.99) { tone(m_pin,i,30);  delay(30);};
}

void CMelodies::r2D2()
{
	Beep(3520,100); //A 
	Beep(3136,100); //G 
	Beep(2637,100); //E 
	Beep(2093,100); //C
	Beep(2349,100); //D 
	Beep(3951,100); //B 
	Beep(2793,100); //F 
	Beep(4186,100); //C 
	Beep(3520,100); //A 
	Beep(3136,100); //G 
	Beep(2637,100); //E 
	Beep(2093,100); //C
	Beep(2349,100); //D 
	Beep(3951,100); //B 
	Beep(2793,100); //F 
	Beep(4186,100); //C 
}

void CMelodies::closeEncounters()
{
	Beep(932,300); //B b
	delay(50);
	Beep(1047,300); //C
	delay(50);
	Beep(831,300); //A b
	delay(50);
	Beep(415,300); //A b
	delay(50);
	Beep(622,500); //E b   
	delay(500);     

	Beep(466,300); //B b
	delay(100);
	Beep(524,300); //C
	delay(100);
	Beep(415,300); //A b
	delay(100);
	Beep(208,300); //A b
	delay(100);
	Beep(311,500); //E b   
	delay(500);  

	Beep(233,300); //B b
	delay(200);
	Beep(262,300); //C
	delay(200);
	Beep(208,300); //A b
	delay(500);
	Beep(104,300); //A bp
	delay(550);
	Beep(156,500); //E b      
}

void CMelodies::ariel()
{
	Beep(1047,300); //C
	delay(50);
	Beep(1175,300); //D
	delay(50);
	Beep(1245,600); //D#
	delay(250);

	Beep(1175,300); //D
	delay(50);
	Beep(1245,300); //D#
	delay(50);
	Beep(1397,600); //F
	delay(250);

	Beep(1047,300); //C
	delay(50);
	Beep(1175,300); //D
	delay(50);
	Beep(1245,500); //D#
	delay(50);          
	Beep(1175,300); //D
	delay(50);
	Beep(1245,300); //D#
	delay(50);             
	Beep(1175,300); //D
	delay(50);
	Beep(1245,300); //D#
	delay(50);
	Beep(1397,600); //F
	delay(50);
}

void CMelodies::uhoh()
{
	Beep(415,100); //C
    delay(80);
    Beep(279,100); //C
    delay(80);
}

void CMelodies::squeak()
{
	for (int i=100; i<5000; i=i*1.45)
	{
		Beep(i,60);
	}
	delay(10);
	for (int i=100; i<6000; i=i*1.5)
	{
		Beep(i,20);
	}
}

void CMelodies::waka()
{
	for (int i=1000; i<3000; i=i*1.05)
	{
		Beep(i,10);
	}
	delay(100);
	for (int i=2000; i>1000; i=i*.95)
	{
		Beep(i,10);
	}
	for (int i=1000; i<3000; i=i*1.05)
	{
		Beep(i,10);
	}
	delay(100);
	for (int i=2000; i>1000; i=i*.95)
	{
		Beep(i,10);
	}
	for (int i=1000; i<3000; i=i*1.05)
	{
		Beep(i,10);
	}
	delay(100);
	for (int i=2000; i>1000; i=i*.95)
	{
		Beep(i,10);
	}
	for (int i=1000; i<3000; i=i*1.05)
	{
		Beep(i,10);
	}
	delay(100);
	for (int i=2000; i>1000; i=i*.95)
	{
		Beep(i,10);
	}
}

void CMelodies::catcall()
{
	for (int i=1000; i<5000; i=i*1.05)
	{
		Beep(i,10);
	}
	delay(300);

	for (int i=1000; i<3000; i=i*1.03)
	{
		Beep(i,10);
	}
	for (int i=3000; i>1000; i=i*.97)
	{
		Beep(i,10);
	}
}

void CMelodies::ohhh()
{
	for (int i=1000; i<2000; i=i*1.02)
	{
		Beep(i, 10);
	}
	for (int i=2000; i>1000; i=i*.98)
	{
		Beep(i, 10);
	}
}

void CMelodies::Glis(int nota1, int nota2, int tasa) {
	// By Dave Tucker: http://dtucker.co.uk/make/arduino-using-my-melodyutils-library-for-r2-d2-style-chirps.html
	// Glissando = Slide
	// Slides up or down from note1 to note2
	// rate = 0 is fast and can be increased to slow the effect down

	if (nota1 < nota2) { //Slide up
		for (int nota = nota1; nota < nota2; nota++) {
			tone(m_pin, nota, tasa); delay(tasa); noTone(m_pin);
		}
	}
	else { //Slide down
		for (int nota = nota1; nota > nota2; nota--) {
			tone(m_pin, nota, tasa); delay(tasa); noTone(m_pin);
		}
	}
	noTone(m_pin);
}

void CMelodies::Beep(int frequencyHertz, long milliseconds)     // the sound producing function  
{
	int x;
	long delayAmount = (long)(1000000 / frequencyHertz);
	long loopTime = (long)((milliseconds * 1000) / (delayAmount * 2));
	for (x = 0; x < loopTime; x++)
	{
		digitalWrite(m_pin, LOW); //HIGH); -> for negated buzzers like in Multifunction shield
		delayMicroseconds(delayAmount);
		digitalWrite(m_pin, HIGH);//LOW);
		delayMicroseconds(delayAmount);
	}
}

#pragma endregion