//connect motordriver to 8,9,10,11 digitial pins of arduino
//connect front ir sensor to 2 digitial pin of arduino
//connect right ir sensor to 3 digitial pin of arduino
//connect back ir sensor to 4 digitial pin of arduino
//connect left ir sensor to 5 digitial pin of arduino
////connect Rx pin of arduino to Tx pin of hc-05 bluetooth trans-reciever 
////connect Tx pin of arduino to Rx pin of hc-05 bluetooth trans-reciever



int Lmotor1 = 11; //initialising Arduino port 10 be be called as LmotorUp
int Lmotor2 = 10; //initialising Arduino port 11 be be called as Lmotor2
int Rmotor1 = 9;  //initialising Arduino port 8 be be called as Rmotor1
int Rmotor2 = 8;  //initialising Arduino port 9 be be called as Rmotor2

int en1 = 12;
int en2 = 13;

int ir1 = 2;
int ir2 = 3;
int ir3 = 4;
int ir4 = 5;
int ir11 = HIGH;
int ir12 = HIGH;
int ir13 = HIGH;
int ir14 = HIGH;

void setup()
{
    Serial.begin(9600);
pinMode(Lmotor1,OUTPUT);//Setting ports as OUTPUTS as they 
pinMode(Lmotor2,OUTPUT);//supply signal values to motor driver
pinMode(Rmotor1,OUTPUT);
pinMode(Rmotor2,OUTPUT);

pinMode(en1,OUTPUT);
pinMode(en2,OUTPUT);
digitalWrite(en1,HIGH);
digitalWrite(en2,HIGH);

pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
pinMode(ir4,INPUT);


Serial.println("AVENTADOR F1 is ready to rock"); //begining statement because i can :P
delay(1000);
} 


void loop()
{
    if(Serial.available() > 0) {//Checking is Serial data available
        ir11= digitalRead(ir1);
        ir12= digitalRead(ir2);
        ir13= digitalRead(ir3);
        ir14= digitalRead(ir4);


        int input = Serial.read(); //Storing value of read data into variable assigned

        switch(input)
        {
            
            case 'w': 
                MoveF(); //Calling respective functions if mathced with case label 
                break;
            
            case 's': 
                MoveB(); // here is it important to use '' as that stores the ASCII value is the letter in the variable
                break;
            
            case 'a': 
                MoveL(); // and hence we can use the int keyword
                break;
            
            case 'd':
                MoveR();
                break;
            
            case 'x':
                Stop();
                break;
            
            default: 
                break;
        }
    }

    delay(50);
}



// Moving forward
void MoveF()
{
    ir11 = digitalRead(ir1);
    if (ir11 == HIGH )
    {
        Serial.println("AVENTADOR F1 Forward");
        digitalWrite(Lmotor1,HIGH); //As said in video we are writing a Digital HIGH to the upper left pin of the motor driver
        digitalWrite(Lmotor2,LOW); //As said in video we are writing a Digital LOW to the lower left pin of the motor driver
        digitalWrite(Rmotor1,HIGH); //As said in video we are writing a Digital HIGH to the upper right pin of the motor driver
        digitalWrite(Rmotor2,LOW); //As said in video we are writing a Digital LOW to the lower right pin of the motor driver

        delay (5000);

        digitalWrite(Lmotor1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
        digitalWrite(Lmotor2,LOW);
        digitalWrite(Rmotor1,LOW);
        digitalWrite(Rmotor2,LOW);
    }
    else {

        Serial.println("AVENTADOR F1 forward obstacle");
    } 
}


// Move backwards
void MoveB()
{
    ir13 = digitalRead(ir3);
    if (ir13 == HIGH )
    {
        Serial.println("AVENTADOR F1 Backward");
        digitalWrite(Lmotor1,LOW); //Reverse logic of above
        digitalWrite(Lmotor2,HIGH);
        digitalWrite(Rmotor1,LOW);
        digitalWrite(Rmotor2,HIGH);
        delay (4000);
        digitalWrite(Lmotor1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
        digitalWrite(Lmotor2,LOW);
        digitalWrite(Rmotor1,LOW);
        digitalWrite(Rmotor2,LOW);
    }
    else {

        Serial.println("AVENTADOR F1 backward obstacle");
    }
}


// Moving left
void MoveL()
{
    ir14 = digitalRead(ir4);
    if (ir14 == HIGH )
    {
        Serial.println("AVENTADOR F1 Left");
        digitalWrite(Lmotor1,LOW); //we are completely stopping the left motor and allowing the right motor to move forward
        digitalWrite(Lmotor2,HIGH); //this will cause the robot to move left
        digitalWrite(Rmotor1,HIGH);
        digitalWrite(Rmotor2,LOW);
        delay (1000);
        digitalWrite(Lmotor1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
        digitalWrite(Lmotor2,LOW);
        digitalWrite(Rmotor1,LOW);
        digitalWrite(Rmotor2,LOW);
    }

    else {

        Serial.println("AVENTADOR F1 Leftside obstacle");
    }

}


// Moving Right
void MoveR()
{
    ir12 = digitalRead(ir2);
    if (ir12 == HIGH )
        {  
            Serial.println("AVENTADOR F1 Right");
            digitalWrite(Lmotor1,HIGH);//we are completely stopping the right motor and allowing the left motor to move forward
            digitalWrite(Lmotor2,LOW);//this will cause the robot to move right
            digitalWrite(Rmotor1,LOW);
            digitalWrite(Rmotor2,HIGH);
            delay (1000);
            digitalWrite(Lmotor1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
            digitalWrite(Lmotor2,LOW);
            digitalWrite(Rmotor1,LOW);
            digitalWrite(Rmotor2,LOW);
        }


    else {

        Serial.println("AVENTADOR F1 Rightside obstacle");
    }

}

void Stop()
{
    Serial.println("AVENTADOR F1 Stop");
    digitalWrite(Lmotor1,LOW);//Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
    digitalWrite(Lmotor2,LOW);
    digitalWrite(Rmotor1,LOW);
    digitalWrite(Rmotor2,LOW);
}
