# Cell Characterization Board
This project is a 10-channel sequential lithium-ion cell (18650) characterization instrument designed to measure cell voltage, discharge current, internal resistance, and capacity under a controlled constant-current load of up to 5 A. The Cell data would be displayed on an LCD and stored on a MicroSD card which can be used to plot discharge curves using Excel/Matlab/Python. Protection features include Reverse Polarity Protection for each channel, Low voltage cut-off and hardware controlled sequential switching circuit with hardware interlock to create mutually exclusive channels.

## Key design goals
- Programmable constant-current discharge
- Accurate, ratiometric voltage and current measurement
- Fault-tolerant handling of reverse polarity and missing cells
- Sequential testing to minimize BOM cost and thermal complexity
- Hardware based protection features for reliability
- Reduce manufacturing and assembly cost as much as possible due to budget constraint
- Clear documentation of design intent and constraints
  
# PCB Design:
## Latest 3D Render:
![Cell Characterization Board V1 2 3D Render - Top](https://github.com/user-attachments/assets/29e0ffa8-d2e8-4c36-aab5-d34a47237cab)
<img width="4265" height="4019" alt="Cell Characterization Board V1 2 3D Render - Bottom" src="https://github.com/user-attachments/assets/4b63f3ed-e3a5-4549-a06e-88446abbb75f" />
## Overview:
The system is implemented on a custom 4-layer mixed-signal PCB (SIG / GND / PWR / SIG) optimized for high-current power handling, precision analog measurement and noise handling. GND and PWR plane are continuous and unbroken providing low-impedance return paths and a stable reference plane. Proper zoning (Analog/Digital/Power) based component placement for noise immunity and short traces. 
### High-Current Routing
- All >2 A paths use wide copper pours with stitching vias if possible to distribute the current
- All high current paths are kept as far away as possible from sensitive analog traces
- Relay coil and Flyback traces are kept as short as possible and fanned out to prevent noise from adjacent traces

### Analog Integrity
- All analog traces are on top layer with a GND plane below and no via jumping
- Analog traces are kept as short as possible, achieved by proper Analog/Digital/Power zones of component placement
- Important analog signals are buffered and have a decoupling capacitor close to it
- Quasi-Kelvin sense (Seperate PWR and SIG traces but shared GND) is used for current and voltage measurement
  
### Noise and Protection
- Relay drive and switching currents are physically separated from the analog front-end
- External flyback diodes placed adjacent to each relay
- Decoupling capacitors placed close to each IC supply pin
- Reverse polarity protection for each channel using P-channel MOSFETs
- V_Cell traces are connected straight to cell holder for qausi-kelvin sense and current limiting resistor on each trace to protect the MUX in case of reverse polarity.
- NTC on Load MOSFET's heatsink for active over temperature protection
- 30 ms Soft start for BUCK IC to prevent overshoot and inrush current

### Debugging
- Testpoints for 5V, 3.3V, 2.5V ref, GND, I_set, Constant Current op-amp feedback line, MOSFET Gate and I_sense.
- External UART, SPI and I2C headers for logic analysis
- MUX-out(Cell voltage) is accessible through MCU header
  
# Hardware
![08e247f1-ca4d-435c-84c2-786f73447f0c-0](https://github.com/user-attachments/assets/2f0dbedd-297c-4e65-9135-7c6beeae0f6e)

## System Architecture Summary (Click subsection header for schematic sheet)
<details>
<summary><h3>Buck and LDO</h3></summary>
  
[![Buck and LDO Schematic](https://github.com/user-attachments/assets/7cbbd1c2-d676-4704-b09d-97c5c336276e)](https://github.com/user-attachments/assets/7cbbd1c2-d676-4704-b09d-97c5c336276e)
</details>

- input DC Jack / XT60: 8–40 V
- input USB-C: 5V 3A (Non-PD)
- 5 V logic rail via AP64502QSP-13 based synchronous buck converter
- Dedicated 3.3 V LDO for MicroSD and SPI

<details>
<summary><h3>Constant Current Sink</h3></summary>
  
[![Constant Current Sink](https://github.com/user-attachments/assets/1adb6a28-354b-4ce8-b8a3-19815ae03084)](https://github.com/user-attachments/assets/1adb6a28-354b-4ce8-b8a3-19815ae03084)
</details>

- IRLZ44N Logic level MOSFET and TLV9162 control op-amp
- Low side 50mohm 3W shunt
- DAC60501ZDGSR 12-bit DAC for precise control of discharge current and controlled via I2C
- Internal 2.5 V precision reference of DAC is shared by ADC as well
- Amplified I_sense signal (0 - 2.5V) using MCP6001 for better resolution
- Theoretical MOSFET temperature with heat sink (θ_normal = 2.6 C/W) at max case is 115.86 C
- Load MOSFET temperature monitoring via NTC
- Maximum discharge current: 5 A

<details>
<summary><h3>MCU</h3></summary>

[![MCU](https://github.com/user-attachments/assets/76e0b13c-49a7-4943-83e6-0d6fc5a95909)](https://github.com/user-attachments/assets/76e0b13c-49a7-4943-83e6-0d6fc5a95909)

</details>

- Compatible with 3.3v STM32 Nucleo boards with nano connectivity like NUCLEO-L432KC and Arduino nano
- External I2C header for debugging and future expansion modules
- External UART header for telemetry

<details>
<summary><h3>Cell Holder</h3></summary>

[![Cell Holder](https://github.com/user-attachments/assets/d6683df6-3a02-4f7b-97c8-28835414f6b9)](https://github.com/user-attachments/assets/d6683df6-3a02-4f7b-97c8-28835414f6b9)

</details>

- DIY 3D printed SMD 18650 cell holders (similar to Keystone 1043) with 0.2mm nickel strips as cell contacts to save BOM cost
- Reverse polarity protection for each channel using MCQ7328-TP P-channel MOSFETs
- Cell voltage sense traces are connected straight to cell holder pads for quasi-kelvin sense

<details>
<summary><h3>Sequential Cell Switching</h3></summary>

[![Sequential Cell Switching](https://github.com/user-attachments/assets/236b81a5-ea0e-4242-863e-f045defb3f62)](https://github.com/user-attachments/assets/236b81a5-ea0e-4242-863e-f045defb3f62)

</details>

- Control Logic: MCU -> I2C Expander -> Line Decoder (For mutually exclusive channels) -> Relay Driver -> Relay -> Cell Holder
- Relay-based physical isolation of cells driven by darlington transistor array on low side
- PCF8575PWR I2C expander for I/O expansion
- CD4514BM96 decoder to prevent connecting more than one channel at the same time and a active high inhibit pin controlled by I2C expander
- External pull ups on all I2C lines and external flyback diodes on all relays

<details>
<summary><h3>Cell Monitoring</h3></summary>

[![Cell Monitoring](https://github.com/user-attachments/assets/edf4d94d-06c7-463c-b50f-4eb45057faaf)](https://github.com/user-attachments/assets/edf4d94d-06c7-463c-b50f-4eb45057faaf)

</details>

- CD74HC4067SM96 16:1 analog MUX for cell voltage sampling
- MUX out is converted to a signal of 0 to 2.5V using a voltage divider and then buffered
- Current limiting resistor(limits to 2.1mA) on each channel to protect the MUX in case of reverse polarity (MUX's internal ESD clamp diode forward biases)

<details>
<summary><h3>MicroSD</h3></summary>

[![MicroSD](https://github.com/user-attachments/assets/e192b704-f8bd-455b-be3e-ed22bf27f31d)](https://github.com/user-attachments/assets/e192b704-f8bd-455b-be3e-ed22bf27f31d)

</details>

- Data is written to MicroSD using SPI
- TXU0304PWR unidirectional voltage level translator for 5V to 3.3V for SCK, MOSI, CS (MCU to MicroSD) and 3.3V to 5V for MISO (MicroSD to MCU)
- SD detect LED for user-friendliness
- Parameters: Time, Cell Voltage, Discharge Current, Internal Resistance, I_set, Cut-off voltage and capacity (mAh / Wh)
- Internal Resistance is calculated using r = (V_OC - V_sense)/I. (Voltage drop across cell under a load)
  



