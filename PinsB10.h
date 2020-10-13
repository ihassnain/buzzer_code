/* PCB board */


/* right leg */
int right_speed_pin = 3;
int rightBrake = 29;
int rightEnable = 30;
int right_direction = 31;

/* left leg */
int left_speed_pin = 2;
int leftBrake = 24;
int leftEnable = 25;
int left_direction = 26;


/* right hand */
int right_hand_pwm = 5;
int right_hand_direction = 33;

/* left hand */
int left_hand_pwm = 4;
int left_hand_direction = 32;

/* neck */
int neck_pwm = 6;
int neck_direction = 34;


/* hedge */
int hedge_reset_pin = 12;


/* obstacle interrupts */
static int front_interrupt_pin = 40;
static int left_interrupt_pin = 41;
static int right_interrupt_pin = 42;
static int back_interrupt_pin = 43;


/* relay pins */
int R1SW_pin = A6; //Relay SW control 1
int R2SW_pin = A7; //Relay SW control 1
bool uv_off = true;
bool relay_high = false;

/* Buz Pin */
int buzz_pin=8;

//return x-y

