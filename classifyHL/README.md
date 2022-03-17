# End to End Scenario

We choose an HVAC system for the scenario as they are familiar systems found in our homes and workplaces.
An HVAC system is a Heating Ventilation, Air Conditioning Unit.
https://en.wikipedia.org/wiki/Heating,_ventilation,_and_air_conditioning

The Azure Sphere device will act as an HVAC system. This works well as several Azure Sphere developer kits 
include built-in sensors for monitoring temperature and pressure. 
For developer kits without sensors then it is easy to simulate those sensors.

## IoT concepts covered

We cover the following IoT concepts in this scenario:

1. Publising telemetry:
   * The current temperature, air pressure, and humidity
   * The HVACs current operating state - Off, Cooling, and Heating
2. Data validation
   * Cloud to device data validation
   * Reporting sensor data out of range faults
3. Remote operations
   * Setting the HVAC target room temperature
   * Setting the rate in seconds the HVAC system publishes telemetry
   * Setting a message on the HVAC display panel
   * Turning the HVAC on and off
   * Restarting the HVAC unit
4. Self-monitoring
   * A watchdog to check the heath of HVAC system and restart if needed.
5. Production considerations
   * How to package and update your applications in production
   * How to pick the best time to update your application with Deferred Updates


## Configuring the application scenario

1. Set ID Scope
1. Set Allowed connections
1. Set DeviceAuthentication

For more information refer to:

1. [Adding the Azure Sphere DevX library](https://github.com/gloveboxes/AzureSphereDevX/wiki/Adding-the-DevX-Library)
1. [Azure Messaging](https://github.com/gloveboxes/AzureSphereDevX/wiki/IoT-Hub-Sending-messages)
1. [Device Twins](https://github.com/gloveboxes/AzureSphereDevX/wiki/IoT-Hub-Device-Twins)
1. [Direct Methods](https://github.com/gloveboxes/AzureSphereDevX/wiki/IoT-Hub-Direct-Methods)
1. [GPIO](https://github.com/gloveboxes/AzureSphereDevX/wiki/Working-with-GPIO)
