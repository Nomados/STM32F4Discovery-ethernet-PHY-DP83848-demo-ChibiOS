/*
 * Licensed under ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" BASIS, 
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ch.h"
#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/* Initial setup of all defined pads, the list is terminated by a {0, 0}.*/
static const spc_siu_init_t spc_siu_init[] = {
  {PCR(PB, PB_LIN0_TDX), PAL_HIGH, PAL_MODE_OUTPUT_ALTERNATE(1)},
  {PCR(PB, PB_LIN0_RDX), PAL_HIGH, PAL_MODE_INPUT},
  {PCR(PE, PE_BUTTON1),  PAL_LOW,  PAL_MODE_INPUT},
  {PCR(PE, PE_BUTTON2),  PAL_LOW,  PAL_MODE_INPUT},
  {PCR(PE, PE_BUTTON3),  PAL_LOW,  PAL_MODE_INPUT},
  {PCR(PE, PE_BUTTON4),  PAL_LOW,  PAL_MODE_INPUT},
  {PCR(PE, PE_LED1),     PAL_HIGH, PAL_MODE_OUTPUT_PUSHPULL},
  {PCR(PE, PE_LED2),     PAL_HIGH, PAL_MODE_OUTPUT_PUSHPULL},
  {PCR(PE, PE_LED3),     PAL_HIGH, PAL_MODE_OUTPUT_PUSHPULL},
  {PCR(PE, PE_LED4),     PAL_HIGH, PAL_MODE_OUTPUT_PUSHPULL},
  {0, 0, 0}
};

/* Initialization array for the PSMI registers.*/
static const uint8_t spc_padsels_init[SPC5_SIU_NUM_PADSELS] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/**
 * @brief   PAL setup.
 */
const PALConfig pal_default_config = {
  PAL_MODE_UNCONNECTED,             /* Default mode for all undefined pads. */
  spc_siu_init,
  spc_padsels_init
};
#endif

/*
 * Early initialization code.
 * This initialization must be performed just after stack setup and before
 * any other initialization.
 */
void __early_init(void) {

  spc_clock_init();

  /* SWT disabled.*/
  SWT.SR.R = 0xC520;
  SWT.SR.R = 0xD928;
  SWT.CR.R = 0xFF00000A;
}

/*
 * Board-specific initialization code.
 */
void boardInit(void) {

}
