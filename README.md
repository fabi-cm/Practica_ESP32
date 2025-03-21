# 🚀 **Proyecto: Sistema de Medición de Distancia con ESP32**

Este proyecto implementa un sistema de medición de distancia utilizando un **ESP32 NodeMCU**, un **sensor ultrasónico (HC-SR04)** y **tres LEDs**. El sistema mide la distancia a un objeto y, según el rango detectado, enciende un LED indicativo.

## 📊 **Funcionamiento del Sistema**

- **Mayor a 50 cm**: Ningún LED encendido.
- **Entre 25 cm y 50 cm**: LED Verde encendido.
- **Entre 15 cm y 25 cm**: LED Amarillo encendido.
- **Menor o igual a 15 cm**: LED Rojo encendido.

### 🛠️ **Componentes Utilizados**

- 1 ESP32 NodeMCU
- 1 Sensor ultrasónico (HC-SR04)
- 3 LEDs (rojo, amarillo, verde)
- 3 Resistencias de 220Ω (para los LEDs)
- Cables de conexión y protoboard

## 📐 **Esquemático de Conexiones**

| Componente            | Pin del ESP32 |
| --------------------- | ------------- |
| **Trigger** (HC-SR04) | GPIO 5        |
| **Echo** (HC-SR04)    | GPIO 18       |
| **LED Rojo**          | GPIO 26       |
| **LED Amarillo**      | GPIO 27       |
| **LED Verde**         | GPIO 14       |
| **GND**               | GND (común)   |

## 📜 **Instrucciones de Instalación**

### 1. **Configurar el Entorno**

1. Instalar **Arduino IDE** ([https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)).

2. Agregar compatibilidad con **ESP32**:

   - Abrir **Arduino IDE**.

   - Ir a **Tools > Board**.

   - Ir a **Board > Boards Manager**.

   - Buscar **ESP32** e instalarlo.

3. Seleccionar la placa **ESP32 NodeMCU**.

### 2. **Cargar el Código**

1. Conecta el **ESP32** al computador mediante USB.
2. En caso de que no reconosca el usb el COM, instalar este driver: ([CP210x Windows Drivers](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads))
3. Copia el código en el **Arduino IDE**.
4. Verifica y sube el programa.

## 🔍 **Pruebas Realizadas**

| Distancia (cm)     | LED Encendido          |
| ------------------ | ---------------------- |
| Mayor a 50 cm      | Ninguno                |
| Entre 25 y 50 cm   | LED Verde (GPIO 14)    |
| Entre 15 y 25 cm   | LED Amarillo (GPIO 27) |
| Menor o igual a 15 | LED Rojo (GPIO 26)     |

## 📢 **Conclusiones**

- El sistema detecta correctamente las distancias en tiempo real.
- El ESP32 responde eficientemente a las señales del sensor ultrasónico.
- Se recomienda usar un **Level Shifter** para proteger el GPIO del ESP32 si se usan sensores ultrasónicos de 5V.

## 🤝 **Contribuciones**

Las contribuciones son bienvenidas. Si deseas mejorar el código o añadir nuevas funciones, no dudes en abrir un *pull request*, si es que quieres hacerlo XD, o dar mejor nota plis.

## 📄 **Licencia**

Este proyecto está bajo la licencia **Libre**, se libre de usarlo sin ninguna consecuensia.

