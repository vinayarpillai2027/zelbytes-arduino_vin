/*
 * calibration.h - LDR Calibration Constants
 * 
 * Circuit: LDR to 5V, 10kΩ to GND (pull-down)
 * Date: 2026-06-05
 * 
 * Your Measured Values:
 *   Pitch Dark (covered):  0
 *   Ambient (room light):  818
 *   Bright (flashlight):   986
 */

#ifndef CALIBRATION_H
#define CALIBRATION_H

// Your calibration points
#define MY_LDR_DARK       0
#define MY_LDR_AMBIENT    818
#define MY_LDR_BRIGHT     986

// Light threshold bands
#define THRESHOLD_DARK     100
#define THRESHOLD_DIM      400
#define THRESHOLD_AMBIENT  700
#define THRESHOLD_BRIGHT   900

// Circuit parameters
#define LDR_PIN            A0
#define R_FIXED_KOHM       10.0
#define VREF_VOLTS         5.0

#endif
