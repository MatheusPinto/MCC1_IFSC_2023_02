/***************************************************************************************
 * @file motor.h
 * @version 1.0
 * @date 28/11/2023
 * @brief File with implementations of the Timer/PWM (TPM) Modules for the Kinetis KL05 Family.
 * @details None.
 * @author Cicero Eduardo Dick Junior
 ***************************************************************************************/
#ifndef SOURCES_MOTOR_H_
#define SOURCES_MOTOR_H_

#include <common.h>

/**
 * @brief Activates TPM0 and TPM1 to count and set de PWM for the motors.
 * @param None
 */
void MOTOR_Init(void);

/**
 * @brief Activates the chanels for the robot move forward
 * @param speed - Adjusts the PWM Duty Cycle to control the robot speed
 */
void MOTOR_Forward(uint16_t speed);


/**
 * @brief Activates the chanels for the robot move barckwards
 * @param speed - Adjusts the PWM Duty Cycle to control the robot speed
 */
void MOTOR_Backward(uint16_t speed);

/**
 * @brief Activates the chanels for the robot move for the left
 * @param speed - Adjusts the PWM Duty Cycle to control the robot speed
 */
void MOTOR_Left(uint16_t speed);

/**
 * @brief Activates the chanels for the robot move for the right
 * @param speed - Adjusts the PWM Duty Cycle to control the robot speed
 */
void MOTOR_Right(uint16_t speed);

/**
 * @brief Disable the PWM chanels to stop the robot completely
 * @param speed - Adjusts the PWM Duty Cycle to control the robot speed
 */
void MOTOR_Stop();



#endif /* SOURCES_MOTOR_H_ */
