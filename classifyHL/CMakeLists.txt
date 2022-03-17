#  Copyright (c) Microsoft Corporation. All rights reserved.
#  Licensed under the MIT License.

###################################################################################################################

# Select your developer board by removing the # tag from the beginning of the line

# The default board selected is the AVNET Azure Sphere Starter Kit Revision 1.

# If you are NOT using the AVNET Revision 1 board be sure to comment out the AVNET board

set(AVNET TRUE "AVNET Azure Sphere Starter Kit Revision 1 ")    
# set(AVNET_REV_2 TRUE "AVNET Azure Sphere Starter Kit Revision 2 ")             
###################################################################################################################

cmake_minimum_required (VERSION 3.10)

project (classify_solution C)

# For information on setting tools revision and target api set see 
# https://docs.microsoft.com/en-us/azure-sphere/app-development/using-cmake-functions

# This project is evergreen and will build to the SDK installed
include(tools/cmake/azsphere_config.cmake)
auto_generate_azsphere_config()

add_subdirectory("AzureSphereDevX" out)

# Create executable
add_executable (${PROJECT_NAME} main.c)
target_link_libraries (${PROJECT_NAME} applibs pthread gcc_s c azure_sphere_devx)
target_include_directories(${PROJECT_NAME} PUBLIC AzureSphereDevX/include )
target_include_directories(${PROJECT_NAME} PUBLIC ../IntercoreContract)


if(AVNET)
    add_definitions( -DOEM_AVNET=TRUE )
    azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "../HardwareDefinitions/avnet_mt3620_sk" TARGET_DEFINITION "azure_sphere_learning_path.json")
endif(AVNET)

if(AVNET_REV_2)
    add_definitions( -DOEM_AVNET=TRUE )
    azsphere_target_hardware_definition(${PROJECT_NAME} TARGET_DIRECTORY "../HardwareDefinitions/avnet_mt3620_sk_rev2" TARGET_DEFINITION "azure_sphere_learning_path.json")
endif(AVNET_REV_2)


azsphere_target_add_image_package(${PROJECT_NAME})