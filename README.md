# Edge Impulse classifier and anomaly detection example on Azure Sphere MT3620

This is an example application that runs an embedded Machine Learning model on the *realtime core* of an Azure Sphere MT3620 board, classifying data coming in on the accelerometer. At [Edge Impulse](https://edgeimpulse.com) we enable developers to create the next generation of intelligent device solutions with embedded Machine Learning - especially when it comes to running ML models on microcontrollers.

## Clone the Classify on Azure Sphere repo

```bash
git clone --recurse-submodules https://github.com/gloveboxes/AzureSphereClassify
```

## Install developer todays

For now, required Windows and Visual Studio 2022 and the Azure Sphere SDK.

## Tool chain

On Windows, copy the *AzureSphereRTCoreToolchainEdgeImpulse.cmake* file to the *C:\Program Files (x86)\Microsoft Azure Sphere SDK\CMakeFiles* folder.

more to follow...

## The project is evergreen

This project automatically updates the CMake Azure Sphere configuration to match the Azure Sphere SDK you've installed on your computer. This is fine for a sample, but for production applications, setting the Azure Sphere configuration in CMake should be intentional and tested.

In the CMakeLists.txt file, the auto_generate_azsphere_config CMake function is called to generate the azsphere_configure_tools and azsphere_configure_api settings.

For production applications, remove this block and replace it with the following CMake commands.

```text
azsphere_configure_tools(TOOLS_REVISION "<YOUR_TOOLS_VERSION>")
azsphere_configure_api(TARGET_API_SET "<THE_TARGET_API_SET_YOU_ARE_TESTING_AGAINST")
```
