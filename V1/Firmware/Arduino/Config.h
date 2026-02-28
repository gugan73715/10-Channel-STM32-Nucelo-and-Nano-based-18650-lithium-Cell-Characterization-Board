//USER SETTINGS
const float TEST_CURRENT = 0.20; 
const float V_CUTOFF = 3.00; 

// CALIBIRATION

// I_Set (12bit DAC)
const int STEPS_PER_AMP = 819;
const float CAL_FACTOR_ISET = 0.9091;

// V_Sense
const float V_REF = 2.50;   
const float CAL_FACTOR_VSENSE = 1.966;  

// I_Sense
// Current Sense Calibration (Kept as you said it's fine)
const float CAL_FACTOR_ISENSE = 1.62;    

// Capacity
const float I_OFFSET_MA = 0.0;    

// HARDWARE ADDRESSES

//I2C
#define DAC_ADDR 0x48
#define PCF_ADDR 0x20 

//DAC Internal ADR
#define DAC_REG_REF  0x03
#define DAC_REG_GAIN 0x04
#define DAC_REG_DATA 0x08 
