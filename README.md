# Use Machine Learning and Azure Sphere for predictive maintenance

The complete *end-to-end* documentation is provided on this wiki. Refer to the *table of contents* found on the *right hand side* of this page.

## Watch the 10 minute end-to-end demo

[![](./wiki/media/predictive_maintenace_youtube.png)](https://youtu.be/62XKxzRld28)

## Introduction

The HVAC system was chosen for the scenario as they are familiar systems found in our homes and workplaces. An HVAC system is a Heating Ventilation, Air Conditioning Unit. Refer to the [Heating, ventilation, and air conditioning](https://en.wikipedia.org/wiki/Heating,_ventilation,_and_air_conditioning) wikipedia article for more information.

The Avnet Azure Sphere Start Kit will act as an HVAC system as it includes several useful sensors including an accelerometer that will be used to feed the TinyML predictive model to determine if the HVAC system requires maintenance.

![HVAC System](https://upload.wikimedia.org/wikipedia/commons/9/90/Rooftop_Packaged_Units.JPG)

## Predictive maintenance solution architecture

![This image shows the predictive maintenance solution architecture](media/predictive_maintenance_solution_architecture.png)