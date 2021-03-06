# GameEngine-Cpp_OpenGL_PhysX

Hi!
This folder contains everything about my game engine that is during the process of realization.

**Legend:**
* External_Libs ~ contains all external libraries that are used (GLEW, GLFW, GLM).
* Repos ~ contains the project with application (Game engine).
* Versions_And_Notes ~ contains all notes written by me and latest versions of game engine.

**Goals:**
1. Implement rendering system by using OpenGL: 

![image](https://user-images.githubusercontent.com/72278818/132967531-90064a08-7c76-4446-8647-a42ddb85d93b.png)

* GLFW for creating the context and handling windows and user inputs. 
* GLEW for manipulating the context in a modern way and handling platform depended extensions.
* GLM for supporting math operations (matrices, vectors).
3. Implement Collision and Physics system by using PhysX from Nvidia.

![20130308_physx](https://user-images.githubusercontent.com/72278818/132967499-428c2fd5-fbd7-4e26-98aa-c15a98157c6c.jpg)

4. Implement audio system.
5. Implement animation system.
6. Implement AI system.

# Current progress:

**1. Date: 6.08.2021**

**1. Creating the window with context using GLFW and initializing GLEW for using modern OpenGL:**

1.1 Initialization library with GLFW (for creating a window and the context). -> **_glfwInit()_**

1.2 Setting up the window hints ~ window configuration.

1.3 Creating the window ~ getting the pointer to this. -> **_glfwCreateWindow(...)_**

1.4 Setting up the current context to be our window.

1.5 Initialization library with GLEW (for handling OpenGL context in a modern way and using the platform dependend extensions). -> **_glewInit()_**

1.6 Getting the size of frame buffer.

1.7 Setting the view port with the size of frame buffer (width and height). -> **_glViewport(0, 0, bufferWidth, bufferHeight)_**

1.8 Activating the platform depended extensions. -> **_glwExperimental=GL_TRUE_**

1.9 Looping the running window. -> **_glfwWindowShouldClose(mainWindow)_**

1.9.1 Polling the events (like user input). -> **_glfwPollEvents()_**

1.9.2 Clearing the screen with red color. -> **_glClearColor(...) and then glClear(GL_COLOR_BUFFER_BIT)_**

1.9.3 Swaping buffers. -> **_glfwSwapBuffers(mainWindow)_**

1.10 Window with the context is created.

**Effect:**

![image](https://user-images.githubusercontent.com/72278818/128518820-7ddc77f0-a302-4de6-8367-76a57da42c92.png)

**2. Date: 9.08.2021**

**Drawing first triangle:**

**1. Setting up the VAO (The thing that we are going to draw):** 

1.1 Creating the VAO (Vertex Array Objects).

1.2 Binding the VAO.

1.3 Creating the VBO (Vertex Buffer Objects).

1.4 Binding the VBO.

1.5 Inserting the data filled with vertices to VBO.

1.6 Set up the attribute pointers.

1.7 Done VAO.


**2. Setting up the program with shaders:**

2.1 Creatng empty program.

2.2 Creating empty shaders.

2.3 Filling the shaders with source code.

2.4 Compiling the shaders.

2.5 Linking the shaders to one program.

2.6 Validing the program.

2.7 Shader program is done.


**3. Drawing the triangle:**

3.1 Binding the Shader Program.

3.2 Binding the VAO.

3.3 Calling the function glDrawArrays to draw the triangle.

3.4 Unbinding the Shader Program.

3.5 Unbinding the VAO.

3.6 Triangle is drawn.

**General idea is: First bind the shader program, then send/set data to uniforms in the shader program and then render object!**

**Rendering pipeline:**

![image](https://user-images.githubusercontent.com/72278818/133353650-dfd49ff2-d827-497f-8b6a-7f2b1ae6c564.png)

**Effect:**

![image](https://user-images.githubusercontent.com/72278818/128777097-bc424d23-56b7-4c5d-b0ab-b6aa6b4274f2.png)

**3. Date: 10.08.2021**

Moving window by using uniforms (the easiest way -> without model matrices):

![window_moving](https://user-images.githubusercontent.com/72278818/128925107-7e71ac97-a1b1-48f2-a3f9-dc1ac24f1a77.gif)

**4. Date: 11.08.2021**

Appling operations to the triangle by using uniforms and _**model matrices:**_
1. Creating uniform variable in the vertex shader ex.: with name **_"model"_**.
2. Storing information about location of uniform variable in the appliacation variable. -> **_uniformModel = glGetUniformLocation(shader, "model")_**
3. Passing the data do program shader that will be stored in the uniform variable. -> **_glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model))_**

**To remember:**

Rotation is always applied about the pivot point which is [0, 0, 0] (center of the screen).
So if we first move the object and then rotate, we will have diffrent result than first rotate and then move.

a) **Translation:**

**Theory:**

![image](https://user-images.githubusercontent.com/72278818/133167777-45677134-3cdb-4441-af32-d68981f37ff8.png)

**Effect:**

![window_moving_translation_model_matrices](https://user-images.githubusercontent.com/72278818/129083963-c3e6e636-8b54-4472-bbc7-8a3d4bb4aac3.gif)

b) **Rotation:**

**Theory:**

![image](https://user-images.githubusercontent.com/72278818/133167921-c6e905f3-0a9c-46c8-a773-1e63de517ff6.png)

**Angle must be in radians.**

**Effect:**

![rotation_by_using_uniforms_model_matrices](https://user-images.githubusercontent.com/72278818/129088692-66de82a2-ada7-4d30-9888-f5951a89c0cf.gif)

c) **Scaling:**

**Theory:**

![image](https://user-images.githubusercontent.com/72278818/133167801-25e1d691-6e91-4abd-9f84-5332a17fd1e1.png)

**Effect:**

![scaling_by_using_uniforms_model_matrices](https://user-images.githubusercontent.com/72278818/129107390-50e9ee26-5106-4b69-9f04-474c6faaf7f9.gif)

d) **Together: Translation, rotation and scaling**

![All_model_matrices_operations_translation_rotation_scaling](https://user-images.githubusercontent.com/72278818/129107905-5b436671-7f1e-4c3d-bb81-80bf45792892.gif)

**5. Date: 18.08.2021**

**To remember:**

Theory about coordinate systems and how to move from to another:

**Moving between spaces using matrices:**

**Screen Space** <-(Part of rendering Pipeline)- **Clipping Space** <-(Projection Matrix)- **View Space** <-(View Matrix)- **World Space** <-(Model Matrix)- **Local Space** 

**Setting the position of the vertex according to the camera (in the vertex shader we are using uniform matrices):**

gl_Position = **projection_matrix** (ortogonal or perspective (setting the way of looking from the camera) * **view_matrix** (see from the point of camera) * **model_matrix** (move object in the world space) * **vec4(pos, 1.0)** (local position)

**6. Date: 19.08.2021**

**1. Interpolation** between three points is made during the process of rasterization and fragment shader.
Fragment shader interpolate between values to get a specific one for example if you have red and blue vertex, fragment shader will interpolate between them and the center will be some mix blue and red. You won't notice the interpolation if you have vertecies with the same colour!

**Effect:**

![image](https://user-images.githubusercontent.com/72278818/130041157-e59acef9-8d0e-44f5-aebc-e1efdf8d6168.png)

**2. Indexed Draws**

**Steps:**

**AFTER BINDING VAO:**

1. Put indices in the array.
2. Generate IBO id -> **_glGenBuffers(1, &IBO);_**
3. Bind the IBO with selected id. -> **_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);_**
4. Put the data to this buffer (GL_ELEMENT_ARRAY_BUFFER). -> **_glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);_**
5. Done.

**AFTER THIS BIND VBO**

When we want do draw:

**AFTER BINDING VAO:**
1. Bind the IBO -> **_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, "ID of IBO");_**
2. Draw the elements -> **_gLDrawElements(GL_TRIANGLES, "Number of vertices", "Type of indices", 0);_**

**Effect:**

**a) Without Depth Test:**

![pyramid](https://user-images.githubusercontent.com/72278818/130054273-f91f6823-477c-4239-b92a-6b5599f2adba.gif)

**b) With Depth Test:**

Steps to achive it:
1. Enable the Depth test before setting the viewport. -> **_glEnable(DEPTH_TEST);_**
2. When we are clearing the colour buffer, we have to clear the depth buffer. -> **_glClear(COLOR_BUFFER_BIT | DEPTH_BUFFER_BIT);_**

![pyramid_with_depth_test](https://user-images.githubusercontent.com/72278818/130055414-7c25cfd3-e55a-498b-a923-77e34b18d7cd.gif)

**3. Using projection matrix (how camera would see (not relative, because we are not using view matrix!) things ortogonal/ perspective):**

![image](https://user-images.githubusercontent.com/72278818/133353702-00c80186-d988-416b-943b-b7d0a2fe1092.png)

We are using perspective to achive 3D depth.

![image](https://user-images.githubusercontent.com/72278818/130354262-3966eb04-063c-44f1-a08e-dab70073aabe.png)


To create perspective projection matrix, we have to do:
**glm::mat4 projection = _glm::perspective("angle of looking (usually 45 deg)", "aspect ratio (bufferWidth/ bufferHeight)", "distance near plane (start looking), "far plane(end looking)");_**

We can use projection matrix without using model matrix !

**Effect:**

![projection_matrix](https://user-images.githubusercontent.com/72278818/130062290-6f92d9e4-6790-4df5-b250-4a766310488b.gif)

**4. Abstracting the code and moving it to classes.**

**UML and code:**
![image](https://user-images.githubusercontent.com/72278818/130244276-c08a32da-499c-4224-9df3-2652dbc33d47.png)

**Effect:**

![image](https://user-images.githubusercontent.com/72278818/130121520-ae2eda3e-e1ee-441c-a587-75e40ccaccfc.png)

**7. Date: 22.08.2021**

**Getting the user input and handling mouse and keyboard by using callbacks and setting user pointer.**

![image](https://user-images.githubusercontent.com/72278818/130353044-1fe1e508-aaf0-45e6-8cd8-c9744c3175ab.png)

**Getting the view matrix:**

1. Creating Camera class with fields: position, worldUp, yaw, pitch, front, right, up, moveSpeed, turnSpeed.

![image](https://user-images.githubusercontent.com/72278818/130354179-e819d2d2-e33a-4e57-ac31-0d8d72489069.png)

2. Calculating new front vector based on pitch and yaw:

![image](https://user-images.githubusercontent.com/72278818/130353137-9fed9375-d4eb-495b-a68f-3d12c71acc45.png)

![image](https://user-images.githubusercontent.com/72278818/130353179-ecc351c1-9153-4508-94ed-79f794b49a55.png)

3. Calculating new camera's right vector by using cross product on camera's front vector and world up (sky, standard up).

![image](https://user-images.githubusercontent.com/72278818/130353185-b0268b7c-a616-41dc-a8ef-9d0da6c4408a.png)

4. Calculating new camera's up vector by using cross product on camera's front vector and camera's right vector.

![image](https://user-images.githubusercontent.com/72278818/130353217-39170dd7-55ec-4451-a519-16ccddb3c705.png)

5. Calucating view matrix based on camera's vectors (direction (front), right and up).

![image](https://user-images.githubusercontent.com/72278818/130353236-1837ad5e-ad7c-4877-99a3-996a2946613a.png)

**In the shader we are aplying this view matrix to every vertex (easy).**

**The newest class diagram with code:**

![Diagram_Game_Engine](https://user-images.githubusercontent.com/72278818/130353489-aa2451df-8cc4-4c46-ae95-c3d5b5d799ad.jpg)

**Effect:**

![Moving_Around_Camera](https://user-images.githubusercontent.com/72278818/130354188-0449bcf2-0c8e-4b71-9f4a-33f7c9f119ef.gif)

**8. Date: 27.08.2021**

**Implementing textures to the vertices:**

**Loading the image and setting the texture:**

1. Create variables for storing data: textureID, width, height, bitDepth and file location.
2. Load file and get data with image (unsigned char*) and other params (width, height, bitDepth).
3. Generate texture (similar to VBO/VAO/IBO). -> **_glGenTextures(1, &textureID);_**.
4. Bind the the texture with this id. -> **_glBindTexture(GL_TEXTURE_2D, textureID);_**
5. Set attributes/ params of texture (filters and wrapping). -> **_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T and S, GL_REPEAT);, glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG and Min_FILTER, GL_LINEAR);_**
6. Load the image to texture. -> **glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
	glGenerateMipmap(GL_TEXTURE_2D);**.
7. Generate Mimap. -> **glBindTexture(GL_TEXTURE_2D);**.
8. Unbind texture. -> **_glBindTexture(GL_TEXTURE_2D, 0);_**.
9. Texture is associated with this id :)

**Using the texture:**

1. Activating texture (sampler). -> **_glActiveTexture(GL_TEXTURE0);_**
2. Binding the texture with selected id. -> **_glBindTexture(GL_TEXTURE_2D, textureID);_**
3. Done.

**Setting the texture in fragment shader to fragments:**

1. Getting the the texture via sampler2D.
2. Getting the position of tex coord via in variables from vertex shader (Setting this via attrib pointers and layout locations).
3. Using method: **_color = texture(theTexture, TexCoord);_**
4. Done.

**UML diagram:**

![Diagram_Game_Engine_v0 2](https://user-images.githubusercontent.com/72278818/131906374-f76f0552-4b5a-419c-81c6-ccd3e18a4b46.jpg)

**Effect:**

![textures_gif](https://user-images.githubusercontent.com/72278818/131195688-679c9b52-dcc0-47eb-8056-6dbde155b582.gif)

**9. Date: 12.09.2021**

**Lighting Model:**

![image](https://user-images.githubusercontent.com/72278818/132967201-c8249708-70f7-4f89-910f-d8c892588392.png)

**Phong Lighting Model**- lighting model that is used to create an ilusion of light's reflection. We can achive it by adding three components of lighting together: 

**TARGET: Create the Directional Light (like a sun).**

![image](https://user-images.githubusercontent.com/72278818/133522959-9e4a4529-f537-495a-81e2-be0e75a22a8a.png)

**Light without position and light source.**

All the light coming in parallel together from the infinite distance.

**Needed:**
- colour,
- ambient factor,
- diffuse factor,
- specular factor,
- directon,

**1. Ambient lighting:**

![image](https://user-images.githubusercontent.com/72278818/132967208-33eb9f9d-edf1-4c2d-9a4b-f402d5e7949c.png)

- Lighting that is always present for example like a sun.
- The easiest one.

In order to get the factor of ambient lighting, we have to get the light of colour and strength of ambient.

****Factor of ambient lighting:****

**_ambient = lightColour * ambientStrength_**

****Final colour of fragment:****

**_fragColour = objectColour * ambient_**

Cases:

If ambient is 1 (full light) then all fragment is lit.

Else if ambient is 0.5 (half light) then fragment is in the half of his colour lit.

Else if ambient is 0 (zero light) the fragment is black.

**Effect:**

![image](https://user-images.githubusercontent.com/72278818/132967297-90ff0745-dc4e-464b-bec7-6b1979d04c87.png)

**Class diagram with code:**

![Diagram_Game_Engine_v0 3](https://user-images.githubusercontent.com/72278818/132983280-8374b25c-49ad-41d6-b9cf-fb1ee3d83ea8.jpg)

**2. Diffuse Lighting/ Phong Interpolation**

![image](https://user-images.githubusercontent.com/72278818/132994750-e465f5e3-f5c7-4740-b4f4-412cb20a1f41.png)

- Lighting that is part of phong lighting model that simulate the angle of incidence of light. 
- The light is determinted by the direction of the light source. Bigger angel of the ray from the light source, makes object more dark.

In order to get the angle, we are using dot product on the normalized normal vector from the surface and light source. 

![image](https://user-images.githubusercontent.com/72278818/132994894-e4ec3b42-5bcf-4069-988b-7b30c9f4d7da.png)

**Final equation:**

_v1*v2 = |v1|*|v2| cos(alfa)_

v1 and v2 are normalized so diffuse factor is:

_v1*v2 = cos(alfa)_

Final form:

**_fragColour = objectColour * (ambient + diffuse)_**

**Creating the diffuse lighting:**
1. Setting up the direction of light (like a sun).
2. Setting up the diffuse intensity (power of the sun).
3. Setting up the color of the light that sun crates (white).
4. Getting the uniforms location for these things from the shader program.
5. Setting up the normals in the buffer data for the each vertex. In this case I'm going to use Phong Shading to create the ilusion of the smooth that is opposite to the flat shading.

![image](https://user-images.githubusercontent.com/72278818/132996457-bff0334d-6724-426e-8897-ad0f8b4fa90b.png)

![image](https://user-images.githubusercontent.com/72278818/132995960-bfdb7ef1-44af-460a-83be-0b2d289d5535.png)

![Wazne_Normals](https://user-images.githubusercontent.com/72278818/133085567-2b563e11-6a56-4e95-ad6e-421b458be855.png)

![image](https://user-images.githubusercontent.com/72278818/133353494-cfc80348-9584-4a52-ac45-d4eee4dfe51a.png)

6. Calculating the normals by using average normals from the surface. One triangle with three vertices will have calcaluted the average normal vector values for each vertex. After this Phong Interpolation will happen during the rendering pipeline.

![image](https://user-images.githubusercontent.com/72278818/132995832-cd112047-edd2-4dc1-8ba3-24aeeea1779f.png)

7. Calculating the diffuse factor in the shader by using the dot product on the normal and the direction of the light.
8. Calculating the diffuse colour with multiplying colour of the light times intensity of the light times diffuse factor.
9. Summing up this diffuse colour with ambient colour multiplying with texture colour.

**Shaders:**
![image](https://user-images.githubusercontent.com/72278818/132996029-d0b8f6eb-f354-41d4-b436-814620f5d6b4.png)

**Diagram UML:**

![Diagram_Game_Engine_v0 3](https://user-images.githubusercontent.com/72278818/132996450-87731e3b-ef1b-4c03-a432-c5643aceff49.jpg)

**Effect:**

**Phong Shading:**

![Phong_Shading](https://user-images.githubusercontent.com/72278818/133098527-6c7bd684-c0da-485b-87fa-c3a636da1594.gif)

**Flat Shading:**

![Flat_Shading](https://user-images.githubusercontent.com/72278818/133099647-200a8c0a-8a97-4686-bd93-6391ce410819.gif)

**3. Specular Lighting**

![image](https://user-images.githubusercontent.com/72278818/133165573-54857584-9ae8-44eb-9f78-18fe8e02481f.png)

**Description:**
- It's directed reflected light source.
- Position of the viewer/ camera is needed.
- Makes the mirror effect.
- Combined with ambient lighting and diffuse lighting, gives us Phong Lighting Model.

**Needed Vectors:** 
- light source, 
- normal, 
- light reflection,
- viewer/ camera,

To calculate factor, we need **angle** between the viewer/ camera and the reflected light source around the normal. If angle is bigger then we have smaller light, and if the angle is smaller then we have more light.
To get the angle we need the view/ camera vector and reflected light vector. 
We can achive the reflected light vector by reflecting light source around the normal vector.

We use **dot product** on these vectors (reflected_light and viewer) to get specular factor.

![image](https://user-images.githubusercontent.com/72278818/133167583-ea21022e-d70f-42d2-aaa1-d61c9f94463a.png)

The next step is to apply the material to the object with shininees property. 
If shininess is bigger then object has more metalic material like metalic ball or knife.
If shininess is smaller then object has more soft/mate material like wood oraz skin.

![image](https://user-images.githubusercontent.com/72278818/133166908-62ccad29-83f1-46ed-94a7-0e5ea66f7bdf.png)

**Equation of specular factor:**

![image](https://user-images.githubusercontent.com/72278818/133167446-3bf50bd6-8ea9-43d3-b381-3cfba53a0b89.png)

**Final equation of Phong Lighting model:**

![image](https://user-images.githubusercontent.com/72278818/133167470-ad091165-e576-4a3e-9adf-9785b38eb9b1.png)

**Shaders:**

![image](https://user-images.githubusercontent.com/72278818/133167315-e694e54c-654c-4440-b1a8-b3f0f108d0b0.png)

**UML diagram:**

![Diagram_Game_Engine_v0 4](https://user-images.githubusercontent.com/72278818/133243186-971b207c-e751-411d-a823-3b9426aa47b9.jpg)

**Effect:**

![Specular_lighting](https://user-images.githubusercontent.com/72278818/133249685-8231219a-3165-47ae-942d-a16d57680f8c.gif)

**Kind of lights:**

**1. Spot Lights**

![image](https://user-images.githubusercontent.com/72278818/133519162-8a2b24ee-c406-464a-ac34-4caae8cdd56a.png)

- Light with **position** and emits in every direction.
- Direction is automatically calculated by using fragment position and the lights source. We can get the fragment position by using the idea of the OpenGL interpolation in the shader. Every fragment has a colour and position.
- We can use math for direcational light to calculate the direction vector.

**Attenuation:**

We can achive it by using reciprocal of quadratic function, where the **x** is the distance between the light source and the position of the fragment. 

![image](https://user-images.githubusercontent.com/72278818/133520311-b9dc72b6-9e1f-4c5f-af57-31804b29d0cf.png)

**Equation:**

![image](https://user-images.githubusercontent.com/72278818/133521184-c54ce98b-ec5b-487b-b1b1-37b0d6d856bf.png)

**Where:**

**Distance**- distance between the fragment and the light source.

**Quadratic**- user defined value, usually the lowest one.

**Linear**- user defined value, usually lower than constant.

**Constant**- usually 1.0, because denumerical must be always greater or equal 1.0.

**Diagram UML:**

![Diagram_Game_Engine_v0 5](https://user-images.githubusercontent.com/72278818/133597952-b33aa571-60ee-4d9e-9fb0-99e1d7976a19.jpg)

**Shaders:**

**Vertex shader:**
```GLSL
#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;

out vec4 vCol;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	
	TexCoord = tex;
	
	Normal = mat3(transpose(inverse(model))) * norm;
	
	FragPos = (model * vec4(pos, 1.0)).xyz; 
}
```

**Fragment shader:**

```GLSL
#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 colour;

const int MAX_POINT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];

uniform sampler2D theTexture;
uniform Material material;

uniform vec3 eyePosition;

vec4 CalcLightByDirection(Light light, vec3 direction)
{
	vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
	
	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour * light.diffuseIntensity * diffuseFactor, 1.0f);
	
	vec4 specularColour = vec4(0, 0, 0, 0);
	
	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);
		vec3 reflectedVertex = normalize(reflect(direction, normalize(Normal)));
		
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}

	return (ambientColour + diffuseColour + specularColour);
}

vec4 CalcDirectionalLight()
{
	return CalcLightByDirection(directionalLight.base, directionalLight.direction);
}

vec4 CalcPointLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < pointLightCount; i++)
	{
		vec3 direction = FragPos - pointLights[i].position;
		float distance = length(direction);
		direction = normalize(direction);
		
		vec4 colour = CalcLightByDirection(pointLights[i].base, direction);
		float attenuation = pointLights[i].exponent * distance * distance +
							pointLights[i].linear * distance +
							pointLights[i].constant;
		
		totalColour += (colour / attenuation);
	}
	
	return totalColour;
}

void main()
{
	vec4 finalColour = CalcDirectionalLight();
	finalColour += CalcPointLights();
	
	colour = texture(theTexture, TexCoord) * finalColour;
}
```
**Effect:**

![lights](https://user-images.githubusercontent.com/72278818/133621263-44df656d-09a7-4875-8f72-2ef5721cce1d.gif)

![lights02](https://user-images.githubusercontent.com/72278818/133622555-27691fab-093d-4ba0-b9d9-7b872eaacd48.gif)

**Spot lights:**

![image](https://user-images.githubusercontent.com/72278818/133805834-ed5600d3-7d54-4355-af16-f6fe7c4c814c.png)

Works similar to point lights.

**Has:**

**- position** ~ position of light source.

**- attenuation factor** ~ fading.

**- direction** ~ front of the light source.

**- cut-off angle** ~ describes edges of the light.

![image](https://user-images.githubusercontent.com/72278818/133806568-5a6d27e0-e7f6-4cbc-8891-2157f93bfb7f.png)

We need a way to compare "angle to fragment" with "cut off angle". We can do it by using **dot product**.

**Equation:**

![image](https://user-images.githubusercontent.com/72278818/133806839-87aca983-b749-49d0-b2aa-ad555b04324a.png)

**Where:**

**- lightVector** ~ vector from the light source to fragment.

**- lightDirection** ~ front of the light source (the direction that light facing).

Angle to fragment will have values between 0 and 1.

**Fading edges:**

We can fade the edges of the spot light by using scaling.

**General equation for scaling:**

![image](https://user-images.githubusercontent.com/72278818/133807325-5ff4ddff-daad-4e30-98aa-7fd2ed172e2f.png)

**Our equation for scaling the values of edges/ fading:**

![image](https://user-images.githubusercontent.com/72278818/133807389-05a3d7c5-8200-48fb-b623-7fbafdea31f9.png)

**Summary:**

![image](https://user-images.githubusercontent.com/72278818/133807470-34a4fb37-fbf5-45cd-9a6e-9e76a4492a13.png)

**UML diagram:**

![Diagram_Game_Engine_v0 6](https://user-images.githubusercontent.com/72278818/133807506-81680654-2afd-43f2-98a7-9113df8fd83c.jpg)

**Shaders:**

**Vertex shader:**

```GLSL
#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;

out vec4 vCol;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	
	TexCoord = tex;
	
	Normal = mat3(transpose(inverse(model))) * norm;
	
	FragPos = (model * vec4(pos, 1.0)).xyz; 
}
```

**Fragment Shader:**

```GLSL
#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

out vec4 colour;

const int MAX_POINT_LIGHTS = 3;
const int MAX_SPOT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct SpotLight
{
	PointLight base;
	vec3 direction;
	float edge;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;
uniform int spotLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform sampler2D theTexture;
uniform Material material;

uniform vec3 eyePosition;

vec4 CalcLightByDirection(Light light, vec3 direction)
{
	vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
	
	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour * light.diffuseIntensity * diffuseFactor, 1.0f);
	
	vec4 specularColour = vec4(0, 0, 0, 0);
	
	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);
		vec3 reflectedVertex = normalize(reflect(direction, normalize(Normal)));
		
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}

	return (ambientColour + diffuseColour + specularColour);
}

vec4 CalcDirectionalLight()
{
	return CalcLightByDirection(directionalLight.base, directionalLight.direction);
}

vec4 CalcPointLight(PointLight pLight)
{
	vec3 direction = FragPos - pLight.position;
	float distance = length(direction);
	direction = normalize(direction);
	
	vec4 colour = CalcLightByDirection(pLight.base, direction);
	float attenuation = pLight.exponent * distance * distance +
						pLight.linear * distance +
						pLight.constant;
	
	return (colour / attenuation);
}

vec4 CalcSpotLight(SpotLight sLight)
{
	vec3 rayDirection = normalize(FragPos - sLight.base.position);
	float slFactor = dot(rayDirection, sLight.direction);
	
	if(slFactor > sLight.edge)
	{
		vec4 colour = CalcPointLight(sLight.base);
		
		return colour * (1.0f - (1.0f - slFactor)*(1.0f/(1.0f - sLight.edge)));
		
	} else {
		return vec4(0, 0, 0, 0);
	}
}

vec4 CalcPointLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < pointLightCount; i++)
	{		
		totalColour += CalcPointLight(pointLights[i]);
	}
	
	return totalColour;
}

vec4 CalcSpotLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < spotLightCount; i++)
	{		
		totalColour += CalcSpotLight(spotLights[i]);
	}
	
	return totalColour;
}

void main()
{
	vec4 finalColour = CalcDirectionalLight();
	finalColour += CalcPointLights();
	finalColour += CalcSpotLights();
	
	colour = texture(theTexture, TexCoord) * finalColour;
}
```
**Effect:**

![Spot_Light](https://user-images.githubusercontent.com/72278818/133827578-494cd9f3-ffe8-478d-82e7-f31be9f5801d.gif)

**10. Date: 19.09.2021**

**Model importing:**

Model importing will be done by using **Assimp** (Open Asset Import Library). It is a portable Open-Source library to import various well-known 3D model formats in a uniform manner. The most recent version also knows how to export 3d files and is therefore suitable as general-purpose 3D model converter. Also assimp aims to provide a full asset conversion pipeline for use in game engines/ realtime rendering systems of any kind.

**Assimp features:**
- Written in portable, ISO-complian C++ (C++ 11 supported).
- Easily configurable and customizable build via cmake.
- Core interface/ API is provided for both C++ and C.
- Easy to configure Post-procssing pipeline.
- Command-line interace to perform common operations (i.e. quick files stats, convert models, extract embedded textures) from the shell.
- Imports bones, vertex weights and animations (i.e. skinning, skeletal animations).
- Loads multiple UV and vertex color channels (current limit is 8).
- Works well with UNICODE input files.
- Supports complex multi-layer materials.
- Supports embedded textures, both compressed (e.q. PNG) or just raw color data.
- No external dependecies (zlib, zlib and irrxml are also needed, but they're included in the repository so you don't need to bother).
- Due to its export interface, Assimp serves as general purpose 3D model converter.

**Diagram of Assimp:**

![image](https://user-images.githubusercontent.com/72278818/133923727-11af4453-685d-4813-9bfd-f05a13986094.png)

**Assimp description:**
- All the data of the scene/ model is contained in the **Scene** object like all the meshes and materials. It also contains reference to the **root node** of the scene.
- **The root node** of the scene may contain children nodes (like all other nodes) and could have a set of indices that point to** the mesh data in the scene object's _mMeshes_ array. The scene's _mMeshes_ array contains the actual **Mesh** objects, the values in the _mMeshes_ array of node are only indices for the scene's meshes array.
- A **Mesh** object itself contains all the relevant data required for rendering: vertex positions, texture cordinates, normal fectors, faces and the material of the object.
- A mesh contains several faces. A **Face** represents a render primitive of the object (triangles, squares, points). A face contains the indices of the vertices that from a primitive. Because the vertices and the indices are seperated, this makes it easy for us to render via an index buffer.
- Finally a mesh also links to a **Material** object that hosts several functions to retrieve the material proporties of an object. Think of texture maps (like diffuse and specular maps) or colors.

Goal: First load an object into a **Scene** object, recursively retrieve the correspoding indices of **Mesh** objects from each of the nodes (we recursively search each node's children), and process each **Mesh** object to retrieve the vertex data, indices and its material proporties (texture maps (diffuse and specular maps) or colors).

**UML diagram:**

![Diagram_Game_Engine_v0 6](https://user-images.githubusercontent.com/72278818/133925057-62ed0d6c-dab7-4ad0-8214-22395cccb521.jpg)

**Effect:**

![object](https://user-images.githubusercontent.com/72278818/133926288-4e423365-e646-48f2-b32f-8d8a6f064f91.gif)

**11. Date: 21.09.2021**

**Directional Shadow Mapping:**

![image](https://user-images.githubusercontent.com/72278818/134219434-a52eeee5-1019-46e7-97d4-8e05aaa22437.png)

![image](https://user-images.githubusercontent.com/72278818/134224638-dbcd26be-2c4c-48a6-adf1-79f35f8aa78a.png)

**General idea:**

We render scene the scene from the perspective of the light (light's point of view) and everything we see from the light's perspective is lit otherwise it must be in shadow. Blue fragments are seen by the light source, black are not seen. We want to get the poin the ray where it first hit an object and compare this closet point to other points on this ray. Then wee do test if a test point's ray position is further down the ray than closest point and if so, the test point must be in shadow. Doing if for every light source ray is a infficient!

We can do something similar, but without casting light rays. Instead, we can use **the depth buffer**. Value in the depth buffer corresponds to the depth of a fragment which is value in [0, 1] from the camera's point of view. We can **render the scene from the light's perspective** and **store the resulting depth values in a texture**. This way, we can sample the **clocest depth values as seen from the _lights' perspective_**. After all, the depth values show the first fragment visible from the light's perspective. We will store all of these depth values in a texture that is called **Shadow Map**.

![image](https://user-images.githubusercontent.com/72278818/134227508-48366f3a-d9de-4f1b-8be2-5732e399ed27.png)

Directional light source (all light rays are parallel) casting a shadow on the surface below the cube. By using the depth values in the depth map we find the closest point and use that to determine whether fragments are in shadow. We **create the depth map by rendering teh scene (from light's perspective) using view and projection matrix (orthogonal) specific to light source.** This project and view matrix together from a transformation **_T_** that transforms any 3D position to the light's (visible) coordinate space. So by applying the **_T_** to the fragment/ position from the viewer perspective, we can get this fragment relative to the light.

In the right image we can see the directional light and the viewer. Firstly we render a fragment at point **_P_** for which we have to determine whether it is in shadow. To do this, we first transform point **_P_** to the **light's  coordinate space by using _T_**. Since point **_P_** is **now as seen from light's perspective**, its **z** coordinate **corresponds to its depth** which in this example is 0.9. Using point **_P_** we can also **index the depth/shadow map** to **obtain the closest visible depth from the light's perspective**, that is at point **_C_** with sampled depth of 0.4. Since indexing the dethp map** returns a depth smaller than depth at point** **_P_** we **canclude** that point **_P_** is in shadow.

**SO: If z value (depth) of current transformed fragment position to light coordinate space is heigher than the value of the closet one = Current Fragment is in the shadow!**

Shadow mapping therefore consists of two passes: 
1. Rendering the depth map/ shadow map.
2. Rendering as normal scene and use the generated depth map to calculate whether the current/s fragments are in shadow..

**1. Rendering the depth map/ shadow map:**

This pass requires to generate a depth map. That is a the depth texture as rendered from the light's perspective that we will be using for testing shadows. To do this we are going to need Frame buffer that will output depths values to the depth/shadow map.

1. Generating the framebuffer object and getting the FBO id.
2. Generating the empty texture and getting the tex id.
3. Binding the empty texture and settin it's params and TexImage2D (GL_DEPTH_COMPONENT is required!).
4. Binding the framebuffer with FBO id and passing to the glFramebufferTexture2D our depth/shadow map, and giving info to not to render any color data (glDrawBuffer(GL_NONE); glReadBuffer(GL_NONE).
5. Unbinding the previous framebuffer.
6. Binding the default framebuffer with our scene.

**Light space transform:**

**a) Projection matrix:**

First pass needs different view and projections matrices than the second one (with final scene). It's need to be relevant to light source. Therefore we are modelling a directional light source so all its light rays are coming in parallel. So our **projection matrix = orthographic projection**. So we have to set the near plane, far plane, size of that camera to the left, right, up and down. After this will have lightProjectio = **_glm::ortho(left, right, bottom, top)_**. We have to be sure that the size of the projection frustum correctly contains the objects that we want to be in the depth map, otherwise our objects or fragments are not in the depth map they will not produce shadows.

**b) View matrix:**

In order to create a view matrix to transform each object to view space relative to the camera position (can be seen from the light's point of view), we can use **_glm::lookAt()_** with the light source's position looking at the scene's center. Position of the view space must have inverse direction of the direction light and the direction of the view matrix is just a direction of the light source.

**SO: T = lightSpaceTransform = lightProjection * lightView**

In the shaders we only care about depth values and not all the fragment (lighting) calculations!

**Calucating the shadow:**

We need to pass to our main **vertex shader** lightSpaceTransform via uniform and after this calculate the current position of the fragment relevant to the light source by using lightSpaceTransform. So **FragPosition_Rel_LightSpace = lightSpaceTransform * Frag_Pos**. Easy. And the we are passing FragPosition_Rel_LightSpace to fragment shader. Whitin the fragment shader we calculate a **shadow** value that is 1 when the fragment is in shadowm oraz 0.0 when it's not. The resulting diffuse and specular components are multiplied by this shadow component. Beacause shadows are rarely completly dark (due to light scattering) we leave the ambient component out the shadow multiplications.

The first thing to check whether a fragment is in shadow, is transform the light-space fragment position in clip-space to normalized device coordinates. When we output a clip-space vertex position to gl_Position in vertex shader, OpenGL automatically does a perspective divide e.g. transform clip-space coordiante in the range [-w, w] to [-1, 1] by dividing the x, y and z component by the vectors's w component. As the clip-space FragPosition_Rel_LightSpace is not passed to the fragment shader through gl_Position, we have to do this **perspective divide** ourselves.

```GLSL
_vec3 projCoords = FragPosition_Rel_LightSpace.xyz / FragPosition_Rel_LightSpace.w;
```

This will return our fragment's light-space position in the range [-1, 1].

When using orthographic projection matrix the w component of vertex remains untouched so this step is actually quite meaningless. However, it is necessary when using perspective projection so keeping this line ensures it works with both projection matrices.

**Because the depth map is in the range _[0, 1]_ and also want to use projCoords to sample from the depth/ shadow map, we transform the NDC coordinates to the range _[0, 1]_**

```GLSL
projCoords = projCoords * 0.5 + 0.5;
```

With these projected coordiantes we can sample the depth map as the resulting [0, 1] coordinates from projCoords directly correspond to the transformed NDC coordinates the first render pass! This gives us the closest depth from the light's point of view:

```GLSL
clocestDepth = texture(shadowMap, projCoords.xy).r;
```

In order to get the current depth at this fragment we simply retrive the projected vector's z coordinate which equals the depth of this fragment from the light's perpsective.

```GLSL
currentDepth = projCoords.z;
```

The actual comparison is then simply a check whether currentDepth is higher than closetDepth and if so, the fragment is in shadow:

```GLSL
shadow = currentDepth > closestDepth ? 1.0 : 0.0;
```

**Together:**

1. Perform perspective divide: **_projCoords = FragPos_Rel_LightSpace.xyz / FragPos_Rel_LightSpace.w;_**.
2. Transform to [0, 1] range: **_projCoords = projCoords * 0.5 + 0.5;_** 
3. Get Closet depth value from the light's perspective (using [0,1] range FragPos_Rel_LightSpace as coords): **_closestDepth=texture(shadowMap, projCoords.xy).r;_**
4. Get depth of current fragment from light's perspective: **_currentDepth = projCoords.z;_**
5. Check whether current frag pos is in shadow: **_shadow = currentDepth > closestDepth ? 1.0 : 0.0;_**

**Problems:**

**1. Shadow Acne:**

It's caused by resolutions problem. Multiple fragments can sample the same value from the depth map when they're relatively far away from the light source. Several fragments then access the same tilted depth texel while some are above and sombe below the floor: we get a shadow discrepancy. Because of this, same fragmetns are considered to be in shadow and some are not, giving the stripped pattern from the image. We can solve this issue with a trick called a **shadow bias** where we simply offset the depth of the source (or the shadow map) by a small amount such that the fragments are not incorrectly considered above the surface.

![image](https://user-images.githubusercontent.com/72278818/134337707-adc9e4e7-864a-4ac1-8947-bd23b0a628b9.png)

![image](https://user-images.githubusercontent.com/72278818/134339025-0749d8b0-5175-4526-a86d-a91c0f929f45.png)

With the bias applied, **all the samples get a depth smaller than surface's depth** and thus the entire surface is correctly lit without widthout any shadows. We can do this by doing such a operation:

```GLSL
bias = 0.004;**
shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;
```

This bias of 0.004 solves an issue of our scene, but the bias is highly dependet on the angle between the light source and the surface. If the surface would have a steep angle to the light source, the shadows may still display shadow acne. A better aproach will be to change the **amount of bias based on the surface angle towards the light**: something we can solve with the **dot product**:

```GLSL
bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
```

We have max. bias of 0.05  and minimum 0.005 based on the surface's normal and light direction. This way surface like the floor that are almost perpendicular to the light source get a small bias, while surfaces lik the cube's sidefaces get a much larger bias.

**2. Peter Panning**

Using bias offset can caused the peter panning effect, so we have to be carefull with that!

![image](https://user-images.githubusercontent.com/72278818/134339042-a60a9242-83ce-4898-8fef-aabaa3f785bd.png)

**3. Oversampling**

What the surfaces behind the frustrum projection to create the shadow map? The values will be behin 0, 1 range and they will always create shadows. To eleminate this problem we have set the type of texture to use the edges with values considered from 0 (always the lowest depth value, so always lit). For values behind the far plane of and greater than 1 -> Initialize to 0.

**4. PCF ~ Percanteage-Closer Filtering**

Edges are limited by the resoultion of the shadow map in which is written. This causes unsightly pixeled edges. Because the depth map has a fixed resolution, the depth frequently usually spans more than one fragment per texel. As reseult, multiple fragments sample the same depth value from the depth map and to the same shadow conclusions which produces these bad edges. We can reduce these blocky shadows by increasing the depth map resolution, or by trying to fit light frustum as closely to the scene as possible.  Another (partial) solution to these jagged edges is called PCF, that is a term that host many differen filtering function that produce softer shadows, making them appear less blocky o hard. The idea is to sample more than once from the depth map, each time with slightly differen texture coordinates. For each individual sample we check wheter it is in shadow or not. All the sub-results are then combined and average and we get a nice soft looking shadow.
One simple implemenatation of PCF is to simply sample the surrounding texels of the depth map and average the results.

For example:

```GLSL
float shadow = 0.0;
vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
for(int x = -1; x <= 1; ++x)
{
	for(int y = -1; y <= 1; ++y)
	{
		float pcf_depth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
		shadow += currentDepth - bias > pcf_Depth ? 1.0 : 0.0;
	}
}

shadow = shadow / 9.0;
```

**TextureSize** returns a vec2 of the width and height of the given sampler texture at mipmap level 0.1 divided over this returns size of a single texel that we use to offset the texture coordinages, making sure each new sample samples a diffrent depth value. Here we sample 9 values around the projected coordinate's x and y value, test for shadow occlusion and finally average the results by the total numer of samples taken. By using more samples/or varying the texelSize variable you can increate the quality of the soft shadows.

**Diagram UML:**

![Diagram_Game_Engine_v0 7](https://user-images.githubusercontent.com/72278818/134350863-a2c225db-8e31-49bf-9c96-85593826af78.jpg)

**Shaders:**

**a) For Rendering Shadow/Depth Pass:**

**Vertex Shader:**

```GLSL
#version 330

layout (location = 0) in vec3 pos;

uniform mat4 model;
uniform mat4 directionalLightTransform; // projection * view

void main()
{
	gl_Position = directionalLightTransform * model * vec4(pos, 1.0); // projection * view * model * origin
}
```

**Fragment Shader:**

``` GLSL
#version 330

void main()
{

}

```

**b) For rendering normal scene and use generated shadow map:**

**Vertex Shader:**

``` GLSL
#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;

out vec4 vCol;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out vec4 DirectionalLightSpacePos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

uniform mat4 directionalLightTransform;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	
	DirectionalLightSpacePos = directionalLightTransform * model * vec4(pos, 1.0);
	
	TexCoord = tex;
	
	Normal = mat3(transpose(inverse(model))) * norm;
	
	FragPos = (model * vec4(pos, 1.0)).xyz; 
}
```

**Fragment Shader:**

``` GLSL
#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec4 DirectionalLightSpacePos;

out vec4 colour;

const int MAX_POINT_LIGHTS = 3;
const int MAX_SPOT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct SpotLight
{
	PointLight base;
	vec3 direction;
	float edge;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;
uniform int spotLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform sampler2D theTexture;
uniform sampler2D directionalShadowMap;

uniform Material material;

uniform vec3 eyePosition;

float CalcDirectionalShadowFactor(DirectionalLight light)
{
	vec3 projCoords = DirectionalLightSpacePos.xyz / DirectionalLightSpacePos.w;
	projCoords = (projCoords * 0.5) + 0.5;
	
	float current = projCoords.z;
	
	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(light.direction);
	
	float bias = max(0.05 * (1 - dot(normal, lightDir)), 0.005);
	
	float shadow = 0.0;
	
	vec2 texelSize = 1.0 / textureSize(directionalShadowMap, 0);
	
	for(int x = -1 ; x <= 1; ++x)
	{
		for(int y = -1 ; y <= 1 ; ++y)
		{
			float pcfDepth= texture(directionalShadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
			shadow += current - bias > pcfDepth ? 1.0 : 0.0;
		}
	}
	
	shadow /= 9;
	
	if(projCoords.z > 1.0)
	{
		shadow = 0.0f;
	}
	
	return shadow;
}

vec4 CalcLightByDirection(Light light, vec3 direction, float shadowFactor)
{
	vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
	
	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour * light.diffuseIntensity * diffuseFactor, 1.0f);
	
	vec4 specularColour = vec4(0, 0, 0, 0);
	
	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);
		vec3 reflectedVertex = normalize(reflect(direction, normalize(Normal)));
		
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}
	
	return (ambientColour + (1.0 - shadowFactor) * (diffuseColour + specularColour));
}

vec4 CalcDirectionalLight()
{
	float shadowFactor = CalcDirectionalShadowFactor(directionalLight);
	return CalcLightByDirection(directionalLight.base, directionalLight.direction, shadowFactor);
}

vec4 CalcPointLight(PointLight pLight)
{
	vec3 direction = FragPos - pLight.position;
	float distance = length(direction);
	direction = normalize(direction);
	
	vec4 colour = CalcLightByDirection(pLight.base, direction, 0.0f);
	float attenuation = pLight.exponent * distance * distance +
						pLight.linear * distance +
						pLight.constant;
	
	return (colour / attenuation);
}

vec4 CalcSpotLight(SpotLight sLight)
{
	vec3 rayDirection = normalize(FragPos - sLight.base.position);
	float slFactor = dot(rayDirection, sLight.direction);
	
	if(slFactor > sLight.edge)
	{
		vec4 colour = CalcPointLight(sLight.base);
		
		return colour * (1.0f - (1.0f - slFactor)*(1.0f/(1.0f - sLight.edge)));
		
	} else {
		return vec4(0, 0, 0, 0);
	}
}

vec4 CalcPointLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < pointLightCount; i++)
	{		
		totalColour += CalcPointLight(pointLights[i]);
	}
	
	return totalColour;
}

vec4 CalcSpotLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < spotLightCount; i++)
	{		
		totalColour += CalcSpotLight(spotLights[i]);
	}
	
	return totalColour;
}

void main()
{
	vec4 finalColour = CalcDirectionalLight();
	finalColour += CalcPointLights();
	finalColour += CalcSpotLights();
	
	colour = texture(theTexture, TexCoord) * finalColour;
}
```
**Effect:**

![direct_light](https://user-images.githubusercontent.com/72278818/134367685-5df11f65-e0e9-4a7e-bf20-4de49357bcb5.gif)

**12. Date: 24.09.2021**

**Omindirectional Shadow Mapping:**
- Used for point lights and spot lights,
- Basic theory is just like for Directional Shadow Mapping but this time we have to handle **shadows in every direction**.
- We can't use only one texture but a lot of these to handle every direction.
- To create this we have to use **a Cubemap**

**Cubemap:**

![image](https://user-images.githubusercontent.com/72278818/134707212-26f38a25-0182-4b71-b1d2-b37f3ed61a08.png)

![image](https://user-images.githubusercontent.com/72278818/134730670-1db6dde4-8d86-4dbe-92ea-96042e712cfe.png)

- Kind of texture in OpenGL,
- Technically it's 6 textures (for one for each side) combined in one, can be referenced by one in GLSL.

**_glBindTexture(GL_TEXTURE_CUBE_MAP, dethpCubemap);_**
**_glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, ...);_**
**GL_TEXTURE_CUBE_MAP_POSITIVE_X;**
**GL_TEXTURE_CUBE_MAP_NEGATIVE_X;**
**GL_TEXTURE_CUBE_MAP_POSITIVE_Y;**
**GL_TEXTURE_CUBE_MAP_NEGATIVE_Y**
**GL_TEXTURE_CUBE_MAP_POSITIVE_Z;**
**GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;**

- Every enum is by one incremented, so we can creat an easy loop.
- We don't need to use textures coordinates (u and v).
- We can get a point on the cubemap by using **direction vector**, that is directed on specific texel from the center of cubemap.
- We don't light matrix transfrom like it was needed in Directional Shadow Mapping!

**We need 6 versions of the lights transform (projection x view), for each direction (right: +x, left: -x, up: +y, down: -y, front: +z, back: -z).**

![image](https://user-images.githubusercontent.com/72278818/134708496-a75a4b83-467a-4939-b916-ac75d519101f.png)

![image](https://user-images.githubusercontent.com/72278818/134708776-b1c9ed37-8231-462c-bb8f-823d83c95923.png)

Also we have to use perspective projection for lights transform: **_glm::perspective(gl::radians(90.0f), aspect (width/height), near_plane, far_plane);_**

This 90 degrees perspective will ensure us that all angles about axis are covered, like a box. Width and height must be equal, because this a box and it must have aspect ration that equals 1. Near plane decide about starting point of the camera and the far plane decides how far away camer can see.

We are creating the view matrix of the light by using position and direction of the light.

![image](https://user-images.githubusercontent.com/72278818/134708906-39364521-9f35-4b00-864a-2aca71a7545d.png)

Direction is "lightPos + vec3(1.0, 0.0, 0.0)", beacuse that light is directed to the right. In another words, it's in positive x direction.

**TARGET: Create and fill Cubemap with 6 textures (left, right, up, down, front, back) that will show the world from diffrent perspective of the light.**

**First Approach:**

Create six different light's transform matrices and use them the same way like in Directional Shadow Mapping. In another words, do 6 shadow passes with each time diffrent perspective (projection x view_i) and store it them in the specifcs frame buffers. When we get 6 different results (filled textures as result of frame buffer) then we will handle it final render pass and set up the finals fragment's of the objects relative to the achived results. **This not the best approach, not efficient!**

**Second Approcach:**

Use the geometry shader and multiply the primitive with light's transform. Do this 6 times in the loop, with every direction/ perspective of the light (projection x view_i) and results of these save in the specific **gl_Layer** and by this will get 6 textures (cubemap) combined in one. And the final shader, we only use direction vector from the light source to the current fragment and this direction will be crossing the cubemap box (the texture) and this point will be the closest depth and the lenght of the direction vector the light source to the fragment will be current depth. In another words, we will have a cubemap that is a texture that will have combined 6 different to create one big one, and by achived this texture we can later use the vector between the light soure and fragment, that will cross the specific face of cube map, and that crossed point texel on the cubemap will have the closest depth value and the length of the vector from the light source to the fragment will be current depth value.

Geometry shader handle primitives and it is between the vertex shader and fragment shader.

Basic structure:

![image](https://user-images.githubusercontent.com/72278818/134727059-d92c817a-e374-49fe-b87f-e9b5267c17c9.png)

**EmitVertex()** ~ Creates a vertex in the position stored in **gl_Position**

**EndPrimitive()** ~ Saves the primitive that is created by the last call of EmitVertex() and then creates a new primitive. 

**Needed passes:**

1. Render to the depth shadow map/ cubemap.
2. Render scene as normal with shadow mapping by using depth cubemap.

**Plan:**
**Generating the depth cubemap:**

1. Creating the cubemap:

```GLSL
usigned int id_depthCubeMap;
glGenTextures(1, &id_depthCubeMap);
```

2. Assigning each of the single cubemap faces as 2D deph-valued texture-image:

```GLSL
int SHADOW_WIDTH = 1024;
int SHADOW_HEIGHT = 1024;
glBindTexture(GL_TEXTURE_CUBE_MAP, id_depthCubeMap);
for(size_t i =0; i < 6; i++)
{
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
}
```

3. Setting the texture parameters:

```GLSL
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
```

4. Connection the frame buffer with the texture:

```GLSL
glBindFramebuffer(GL_FRAMEBUFFER, FBO);
glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, id_depthCubemap, 0);
glDrawBuffer(GL_NONE);
glReadBuffer(GL_NONE);
glBindFramebuffer(GL_FRAMEBUFFER_0);
```

Process is similar to the default shadow mapping but this time we are rendering to and use a cubemap depth texture, not to 2D depth texture.

5. Setting the light space transform:

```GLSL
float nearPlane = 0.0f;
float farPlane = 1.0f;
float aspectRatio = SHADOW_WIDTH / SHADOW_HEIGHT;
glm::mat4 shadowProjection = glm::perspective(glm:: radians(90.0f), aspectRation, nearPlane, farPlane);
```
By setting to 90 degress we make sure that the viewing field is exaclty large enough to fill a single face of the cubemap such that all faces align correctly to each other at the edges. So the projection matrix doesn't change per direction but the view, yes! We need to create 6 transformation matrices, a different view matrix per direction. By using glm::lookAt we can create 6 view directions, each looking at one face direction of the cubemap in the order: right, left, top, bottom, near and far.

```GLSL
std::vector<glm::mat4> shadowTransformationMatrices;
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, -l.0, 0.0);
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(-1.0, 0.0, 0.0), glm::vec3(0.0, -l.0, 0.0);
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 0.0, 1.0);
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, 0.0, -1.0);
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, -1.0, 0.0);
shadowTransformationMatrices.push_back(shadowProjection * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, -1.0, 0.0);
```

So we are creating 6 transform matrices by using the same projection matrix and 6 different views directions, each looking at one face of the cubemap in the specific order (right, left, top, bottom, forward, back).

There transformations matrices are sent to the shaders that render the depth into the cubemap.

**Shaders:**

To render depth values to a depth cubemap we will have three shaders: vertex, geometry and fragment.
Geometry shader will be responsible for transforming all world-space vertices to the 6 different light spaces. So, the vertex shader simply transforms vertices to the world-space and give these values to geometry shader.

**Vertex Shader:**

```GLSL
#version 330

layout (location = 0) in vec3 pos;

uniform mat4 model;

void main()
{
    gl_Position = model * vec4(pos, 1.0);
}
```
After this, geometry shader will tatke as input 3 vertices (triangle vertices) and an uniform array of light space transformation matrices. The geometry shader has a built-in variable called **gl_Layer** that spacifies which cubemap face to emit a primitive to. When left alone, the geometry shader just sends its primitives further down to the pipeline as usual, but when we update this variable we can control to which cubemap face we render to for each primitive. This **only works when we have a cubemap texture attached to teh active framebuffer!!!** Easy.

**Geometry Shader:**

```GLSL
#version 330

layout (triangles) in;
layout (triangle_strip, max_vertices=18) out;

uniform mat4 lightMatrices[6];

out vec4 FragPos;

void main()
{
    for(int face = 0 ; face < 6 ; face++)
    {
        gl_Layer = face;
        for(int i = 0 ; i < 3 ; i++)
        {
            FragPos = gl_in[i].gl_Position;
            gl_Position = lightMatrices[face] * FragPos;
            EmitVertex();
        }
        EndPrimitive();
    }
}
```

To the geometry shader is simple. We taka as input a triangle, and output a total of 6 triangles (6 * 3 = 18 vertices). In the main function we iterate over 6 cubemap face where we specify earch face as the output face by stroring the face integer into gl_Layer. After this we generate the output triangles by transforming each world-space input vertex to the relevant light space by multiplying FragPos with the face's light-space transformation matrix. We also sent the result FragPos variable to the fragment shader that we will need to calculate the depth value.

This time we have to calculate depth as the linear distance between each closest fragment position and the light source's position. 

**Fragment Shader:**

``` GLSL
#version 330

in vec4 FragPos;

uniform vec3 lightPos;
uniform float farPlane;

void main()
{
    float distance = length(FragPos.xyz - lightPos);
    distance = distance/farPlane;
    gl_FragDepth = distance;
}
```

So the fragment shader takes as input the position of current fragment (FragPos) from the geometry shader, the light's position vector, and te frustum's far plane value. Here we take the distance between the current fragment position and the light source, and later map it to the [0, 1] range (depth value) and write it as the fragment's depth value.

Rendering the scene with these shaders and the cubemap-attached to the framebuffer object active will give us a completly filled depth cubemap for the second pass that is going be our finaln pass.

**Mapping shadows:**

The procedure is similar to the directional shadow mapping, but this tme we **bind a cubemap texture** instead of a 2D texture also pass **light projections' far plane** variable to the shaders.

The vertex and fragment shaders are similar to the orignal shadow mapping shaders but the difference is that the fragment shader no longer requires a fragment position in light space as we can now sample the depth values from the direction vector. Because of this, the vertex shader doesn't needs to transfrom its position vectors to the light space. 

The biggest difference is that we are going sample depth values from the cubemap instead of a 2D texture.

Plan:

1. We have to retrieve the depth of the cubemap. In the previous fragment shader we stored the depth as the linear distance between the fragment and the light position. So we are going to take the similar approach:

``` GLSL
vec3 fragToLight = fragPos - lightPos;
float closestDepth = texture(depthMap, fragToLight).r;
```

Here we taking the differenc vetor between the fragment's position and the light's position and use that vector as a direction to sample the cubemap. The direction vector does not need to be a unit verctor to sample from cubemap. The resulting **closestDetph** value is the normalized depth value between the light source and its closest visible fragment. The **closestDetph** value is currently in the range [0, 1] so we first transform it back to [0, far_plane] by multiplying it with far_plane.

```GLSL
closestDepth = closestDeph * far_plane;
```

The next step is to retrieve the depth value between the current fragment and the light source, which we can easily obtain by taking the length of **fragToLight** due to we calculated depth values in the cubemap:

```GLSL
currentDepth = lenght(fragToLight);
```
This will return a depth value in the same range as closestDepth. Now we can compare both depth values to see which is closer than the other and determine wheter the current fragment is in shadow. We will also include a shadow bias so we don't get shadow acne.

```GLSL
bias = 0.05;
shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;
```

**Final plan:**

```GLSL
// 1. Getting the vector between current fragment position and light position.
vec3 fragToLight = fragPos - lightPos;
// 2. Using the light to fragment vector to sample from the depth map.
float closestDepth = texture(depthMap, fragToLight).r;
// 3. It is currently in linear range between [0, 1], so we have to re-transform back this to original value.
closestDepth = closestDepth * far_plane;
// 4. Getting the linear depth as the lenght between the fragment and light position.
float currentDepth = length(fragToLight);
// 5. Determining which values is closer than other. Testing.
float bias = 0.05;
float shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;
```
So with these shaders we get shadows in all surrounding directions from a point light and spot light. 

**Visualizing cubemap depth buffer:**

With one of the obvious checks beoing validating whether the depth map was built correctly. A simple trcik to visualize the depth buffer is to take the closestDetph variable and display that variable as:

```GLSL
FragColor = vec4(vec3(closestDepth/ far_plane), 1.0);
```

And the result is a grayoud out scene where each color represents the linear depth values of the scene. We can also see shadowed regions on the outside wall. If it looks somewhat similar, we know that the depth cubemap was properly generated.

Example from the Internet:

![maxresdefault](https://user-images.githubusercontent.com/72278818/134728998-ce448a03-1426-47b2-a42b-f930be401346.jpg)

**PCF ~ Percantage-Closer Filtering**

- Basically the same concept but with the third dimension,
- Pre-defined user values offset directions vectors.
- We can create these 20 or more.

Optimisation: Pre-define user values offset directions vectors are not relative positions but directions. So we can scale how far the sample is based on the distance from the viewer. 

If the user is closer: Sample closer to the original vector. 

If the user is far: Sample more far from the original vector.

**Code:**

```GLSL
vec3 fragToLight = FragPos - light.position;
float currentDepth = length(fragToLight);
	
float shadow = 0.0;
float bias   = 0.15;
int samples  = 20;
float viewDistance = length(eyePosition - FragPos);
float diskRadius = (1.0 + (viewDistance / omniShadowMaps[shadowIndex].farPlane)) / 25.0;
for(int i = 0; i < samples; ++i)
{
	float closestDepth = texture(omniShadowMaps[shadowIndex].shadowMap, fragToLight + sampleOffsetDirections[i] * diskRadius).r;
	closestDepth *= omniShadowMaps[shadowIndex].farPlane;   // Undo mapping [0;1]
	if(currentDepth - bias > closestDepth)
        {
		shadow += 1.0;
        }
}
shadow /= float(samples);  
	
return shadow;
```

**UML diagram:**

![Diagram_Game_Engine_v0 8](https://user-images.githubusercontent.com/72278818/134735928-62f038d4-5e33-4ce9-9b96-bdf48d806268.jpg)

**Shaders for final rendering:**

**Vertex Shader:**

```GLSL
#version 330

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tex;
layout (location = 2) in vec3 norm;

out vec4 vCol;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;
out vec4 DirectionalLightSpacePos;

uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

uniform mat4 directionalLightTransform;

void main()
{
	gl_Position = projection * view * model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
	
	DirectionalLightSpacePos = directionalLightTransform * model * vec4(pos, 1.0);
	
	TexCoord = tex;
	
	Normal = mat3(transpose(inverse(model))) * norm;
	
	FragPos = (model * vec4(pos, 1.0)).xyz; 
}
```
**Fragment Shader:**

```GLSL
#version 330

in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec4 DirectionalLightSpacePos;

out vec4 colour;

const int MAX_POINT_LIGHTS = 3;
const int MAX_SPOT_LIGHTS = 3;

struct Light
{
	vec3 colour;
	float ambientIntensity;
	float diffuseIntensity;
};

struct DirectionalLight 
{
	Light base;
	vec3 direction;
};

struct PointLight
{
	Light base;
	
	vec3 position;
	float constant;
	float linear;
	float exponent;
};

struct SpotLight
{
	PointLight base;
	vec3 direction;
	float edge;
};

struct OmniShadowMap
{
	samplerCube shadowMap;
	float farPlane;
};

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;
uniform int spotLightCount;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

uniform OmniShadowMap omniShadowMaps[MAX_POINT_LIGHTS + MAX_SPOT_LIGHTS];

uniform sampler2D theTexture;
uniform sampler2D directionalShadowMap;

uniform Material material;

uniform vec3 eyePosition;

vec3 sampleOffsetDirections[20] = vec3[]
(
   vec3(1, 1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1, 1,  1), 
   vec3(1, 1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1, 1, -1),
   vec3(1, 1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1, 1,  0),
   vec3(1, 0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1, 0, -1),
   vec3(0, 1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0, 1, -1)
);

vec4 CalcLightByDirection(Light light, vec3 direction, float shadowFactor)
{
	vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
	
	float diffuseFactor = max(dot(normalize(Normal), normalize(direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour * light.diffuseIntensity * diffuseFactor, 1.0f);
	
	vec4 specularColour = vec4(0, 0, 0, 0);
	
	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);
		vec3 reflectedVertex = normalize(reflect(direction, normalize(Normal)));
		
		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.0f);
		}
	}

	return (ambientColour + (1.0 - shadowFactor) * (diffuseColour + specularColour));
}

float CalcPointShadowFactor(PointLight light, int shadowIndex)
{
	vec3 fragToLight = FragPos - light.position;
	float currentDepth = length(fragToLight);
	
	float shadow = 0.0;
	float bias   = 0.15;
	int samples  = 20;
	float viewDistance = length(eyePosition - FragPos);
	float diskRadius = (1.0 + (viewDistance / omniShadowMaps[shadowIndex].farPlane)) / 25.0;
	for(int i = 0; i < samples; ++i)
	{
		float closestDepth = texture(omniShadowMaps[shadowIndex].shadowMap, fragToLight + sampleOffsetDirections[i] * diskRadius).r;
		closestDepth *= omniShadowMaps[shadowIndex].farPlane;   // Undo mapping [0;1]
		if(currentDepth - bias > closestDepth)
        {
			shadow += 1.0;
        }
	}
	shadow /= float(samples);  
	
	return shadow;
}

float CalcShadowFactor(vec4 DirectionalLightSpacePos)
{
	vec3 projCoords = DirectionalLightSpacePos.xyz / DirectionalLightSpacePos.w;
	projCoords = projCoords * 0.5 + 0.5;
	
	float closestDepth = texture(directionalShadowMap, projCoords.xy).r;
	float currentDepth = projCoords.z;
	
	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(directionalLight.direction);
	float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.0005);
	
	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(directionalShadowMap, 0);
	for(int x = -1; x <= 1; ++x)
	{
		for(int y = -1; y <= 1; ++y)
		{
			float pcfDepth = texture(directionalShadowMap, projCoords.xy + vec2(x,y) * texelSize).r;
			shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
		}
	}
	
	shadow /= 9.0;
	if(projCoords.z > 1.0)
	{
		shadow = 0.0;
	}
	
	return shadow;
}

vec4 CalcDirectionalLight(vec4 DirectionalLightSpacePos)
{
	float ShadowFactor = CalcShadowFactor(DirectionalLightSpacePos);
	return CalcLightByDirection(directionalLight.base, directionalLight.direction, ShadowFactor);
}

vec4 CalcPointLight(PointLight pLight, int shadowIndex)
{
	vec3 direction = FragPos - pLight.position;
	float distance = length(direction);
	direction = normalize(direction);
	
	float shadowFactor = CalcPointShadowFactor(pLight, shadowIndex);
	
	vec4 colour = CalcLightByDirection(pLight.base, direction, shadowFactor);
	float attenuation = pLight.exponent * distance * distance +
						pLight.linear * distance +
						pLight.constant;
	
	return (colour / attenuation);
}

vec4 CalcSpotLight(SpotLight sLight, int shadowIndex)
{
	vec3 rayDirection = normalize(FragPos - sLight.base.position);
	float slFactor = dot(rayDirection, sLight.direction);
	
	if(slFactor > sLight.edge)
	{
		vec4 colour = CalcPointLight(sLight.base, shadowIndex);
		
		return colour * (1.0f - (1.0f - slFactor)*(1.0f/(1.0f - sLight.edge)));
		
	} else {
		return vec4(0, 0, 0, 0);
	}
}

vec4 CalcPointLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < pointLightCount; i++)
	{		
		totalColour += CalcPointLight(pointLights[i], i);
	}
	
	return totalColour;
}

vec4 CalcSpotLights()
{
	vec4 totalColour = vec4(0, 0, 0, 0);
	for(int i = 0; i < spotLightCount; i++)
	{		
		totalColour += CalcSpotLight(spotLights[i], i + pointLightCount);
	}
	
	return totalColour;
}

void main()
{
	vec4 finalColour = CalcDirectionalLight(DirectionalLightSpacePos);
	finalColour += CalcPointLights();
	finalColour += CalcSpotLights();
	
	colour = texture(theTexture, TexCoord) * finalColour;
}
```

**Effect:**

![gf](https://user-images.githubusercontent.com/72278818/134738864-f0830d05-e048-4659-a462-8b4f2f9cb123.gif)

**13. Date: 25.09.2021**

**Skybox:**

![image](https://user-images.githubusercontent.com/72278818/134778138-5201e108-365f-49b3-8233-a77fb0ba0882.png)

- Cubemap that is creating an illusion of bigger world.
- We are using cubemap to texture cube.
- Needs seperate shader to be done before the main.
- Small 1x1x1 cube around the camera.

**General idea:**
1. Create shader program (vertex shader, fragment shader) and get the locations of uniform projection and view, save these locations.
1. Create the cubemap texture filled with 6 images (right: +x, left: -x, up: +y, down: -y, back: +z, front: -z).
2. Create the cube mesh (VAO, VBO, IBO).

**Drawing cubemap:**
1. Disable depth mask (glDepthMask(GL_FLASE)).
2. Use shader (glUseProgram(shaderID)).
3. Attach values to uniforms (uniformProjection, uniformView) from shader (projection matrix and view matrix (without column with translations) (glUniformMatrix4fv(...))
4. Active and bind texture (glActiveTexture(GL_TEXTURE0) -> glBindTexture(GL_TEXTURE_CUBE_MAP, textureId)).
5. Render mesh (glBindVertexArray(VAO) -> glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO) -> glDrawElements(GL_TRIANGLES)).
6. Enable depth mask (glDepthMask(GL_TRUE)).

**In another words:**
1. Initializing shader to use.
2. Binding the VAO of the skybox cubemap.
3. Binding/ attaching the texture of skybox.
4. Rendering skybox.
5. Rendering normal scene.

The drawned cubemap will have the inifite value of depth so everything will in front of us, that's the trick!

![image](https://user-images.githubusercontent.com/72278818/134777898-bc726248-8e66-42cf-bf31-94e1772946bb.png)

**UML diagram:**

![Diagram_Game_Engine_v0 9](https://user-images.githubusercontent.com/72278818/134778316-5988bbd5-834b-4ae9-9965-615bd132792f.jpg)

**Shaders for cubemap:**

We are going to send gl_Position with projection and view matrix but without model matrix. We want to have skybox to be static around camera. 

```GLSL
TexCoords = aPos;
```
Texture's coordinates can use position of fragment. Skybox doesn't move, so it's basically in the origin sa every fragment's position vector is his direction vector. SamplerCube uses vector to find texel so it uses TexCoords vector from vertex vector.

**Vertex Shader:**

```GLSL
#version 330

layout(location = 0) in vec3 pos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    TexCoords = pos;
    gl_Position = projection * view * vec4(pos, 1.0);
}
```

**Fragment Shader:**

```GLSL
#version 330

in vec3 TexCoords;

out vec4 colour;

uniform samplerCube skybox;

void main()
{
    colour = texture(skybox, TexCoords);
}
```
Main shaders are ok!

**Effect:**

![final02](https://user-images.githubusercontent.com/72278818/134786687-7a70d4a4-027a-4342-b9d5-c663d6941479.gif)

![final03](https://user-images.githubusercontent.com/72278818/134786690-d1a96b7f-f338-4b5a-b5eb-feaf60c3164e.gif)
