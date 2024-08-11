/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : app.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/* Development on Bare Metal vs. RTOS
 * (https://www.sysgo.com/professional-articles/bare-metal-vs-rtos)
 */
/*
 * When developing embedded systems that are to be real-time capable, one of
 * the first and most important questions is whether the applications should
 * run under a real-time operating system (RTOS) or whether a bare-metal
 * solution should be developed.
 *
 * Bare-metal programming is generally understood
 * to mean that an application is written directly on the hardware without
 * using an external programming interface, i.e. an operating system.
 *
 * Applications access here directly hardware registers of microcontrollers.
 * Here one helps oneself with approaches such as endless loops, which execute
 * tasks with fixed computing time. This sequential execution is only deviated
 * from when an interrupt event occurs. This bare-metal development approach
 * for embedded systems is therefore also known as super-loop.
 */

/* Event-Triggered Systems (ETS) and Time-Triggered (TTS)
 * (https://ebrary.net/51334/computer_science/time_event_triggered_systems)
 */
/*
 * A trigger is an event that causes the start of some action in the control
 * system. The action may be the execution of a task reading a variable and
 * computing a new value of a correcting variable, or the sending of a message
 * reporting current values of variables like pressure or temperature.
 *
 * In event-triggered control, an action is started only if a significant event
 * occurs. For instance, a sensor would send a message only if the temperature
 * has changed by more than 3°C since the last message was sent.
 *
 * In time-triggered control, all actions are initiated periodically by a
 * real-time clock. The sensor from our example would send a message every
 * clock cycle even if the temperature remains constant.
 */

/* C Programming Language Tutorial (https://www.geeksforgeeks.org/) */
/*
 *  C Basics - C Variables and Constants - C Data Types - C Input/Output
 *  C Operators - C Control Statements Decision-Making - C Functions
 *  C Arrays & Strings - C Pointers - C User-Defined Data Types
 *  C Storage Classes - C Memory Management - C Preprocessor - C File Handling
 *  Miscellaneous
 */

/* Embedded C Coding Standard by Michael Barr
 * www.barrgroup.com/embedded-systems/books/embedded-c-coding-standard */
/*
 *  Introduction - General Rules - Comment Rules - White Space Rules -
 *  Module Rules - Data Type Rules - Procedure Rules - Variable Rules
 *  Statement Rules - Appendices - Bibliography - Index
 */

/* Spaghetti Code (https://www.geeksforgeeks.org/) */
/*
 * Spaghetti Code is nothing but a generalized common-usage term for
 * unstructured and difficult-to-read code.
 *
 * Such a type of code in any large code-base can create problems of its own,
 * if not resolved on time. It can lead to a huge wastage of important
 * resources like time and energy to find bugs and fix them because the code
 * has no structure.
 */

/* Structured Programming Approach with Advantages and Disadvantages
 * (https://www.geeksforgeeks.org/)
 */
/*
 * , as the word suggests, can be defined as a programming approach in which
 * the program is made as a single structure.
 *
 * It means that the code will execute the instruction by instruction one after
 * the other. It doesn’t support the possibility of jumping from one
 * instruction to some other with the help of any statement like GOTO, etc.
 * Therefore, the instructions in this approach will be executed in a serial
 * and structured manner. The languages that support Structured programming
 * approach are:
 *
 *  C
 *  C++
 *  Java
 *  C#
 *  ..etc
 */

/* Introduction of Programming Paradigms
 * (https://www.geeksforgeeks.org/)
 */
/*
 * Paradigm can also be termed as method to solve some problem or do some task.
 * Programming paradigm is an approach to solve problem using some programming
 * language or also we can say it is a method to solve a problem using tools
 * and techniques that are available to us following some approach.
 *
 * There are lots for programming language that are known but all of them need
 * to follow some strategy when they are implemented and this methodology/
 * strategy is paradigms. Apart from varieties of programming language there
 * are lots of paradigms to fulfill each and every demand.
 */

/* Differences between Procedural and Object Oriented Programming
 * (https://www.geeksforgeeks.org/)
 */
/*
 * Procedural Programming can be defined as a programming model which is
 * derived from structured programming, based upon the concept of calling
 * procedure.
 *
 * Procedures, also known as routines, subroutines or functions,
 * simply consist of a series of computational steps to be carried out. During
 * a program’s execution, any given procedure might be called at any point,
 * including by other procedures or itself.
 */

/* Modular Approach in Programming (https://www.geeksforgeeks.org/) */
/*
 * Modular programming is the process of subdividing a computer program into
 * separate sub-programs. A module is a separate software component.
 * It can often be used in a variety of applications and functions with other
 * components of the system.
 */

/* Features of C Programming Language (https://www.geeksforgeeks.org/) */
/*
 * C language is lavishly portable as programs that are written in C language
 * can run and compile on any system with either no or small changes.
 */

/* Static functions in C (https://www.geeksforgeeks.org/) */
/*
 * Unlike global functions in C, access to static functions is restricted to
 * the file where they are declared. Therefore, when we want to restrict
 * access to functions, we make them static. Another reason for making
 * functions static can be the reuse of the same function name in other files.
 */

/* Referencias */
/*
 * SW
 * (https://campusgrado.fi.uba.ar/course/view.php?id=1217&section=10#tabs-tree-start)
 *
 * HW & FW/MW
 * (https://campusgrado.fi.uba.ar/course/view.php?id=1217&section=11#tabs-tree-start)
 *
 * Files & Folders
 * (https://campusgrado.fi.uba.ar/course/view.php?id=1217&section=12#tabs-tree-start)
 */

/********************** inclusions *******************************************/

/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"

/********************** macros and definitions *******************************/

#define G_APP_CNT_INI	0u

/********************** internal data declaration ****************************/

/********************** internal functions declaration ***********************/

/********************** internal data definition *****************************/

const char *p_sys	= " Bare Metal \r\n";
const char *p_app	= " Analog Signal Reading - Interrupt \r\n";

/********************** external data declaration *****************************/

uint32_t g_app_cnt;

volatile uint32_t g_tick_cnt;

/********************** external functions definition ************************/

void app_init(void)
{
	/* Print out: Application Initialized */
	LOGGER_LOG("\r\n");
	LOGGER_LOG("%s is running - Tick [mS] = %d\r\n", GET_NAME(app_init), (int)HAL_GetTick());

	LOGGER_LOG(p_sys);
	LOGGER_LOG(p_app);

	g_app_cnt = G_APP_CNT_INI;

	cycle_counter_init();

	HAL_ADC_Start_IT(&hadc1);
}

void app_update(void)
{
	/* Update App Counter */
	g_app_cnt++;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	uint32_t value = HAL_ADC_GetValue(&hadc1);
	float temperature = (value * 3.3)/ 100;
	LOGGER_LOG("Temperature = %d °C \r\n", (int) temperature);
}

void HAL_SYSTICK_Callback(void)
{
	g_tick_cnt++;
}

/********************** end of file ******************************************/
