
#ifndef _3DSLOADER_H
#define _3DSLOADER_H


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")


#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <fstream>
#include <vector>									
#include <crtdbg.h>
using namespace std;




//////////////////////////////////////
//The tVector3 Struct
//////////////////////////////////////
typedef struct tVector31					// expanded 3D vector struct
{			
	tVector31() {}	// constructor
	tVector31 (float new_x, float new_y, float new_z) // initialize constructor	 
	{x = new_x; y = new_y; z = new_z;}
	// overload + operator so that we easier can add vectors
	tVector31 operator+(tVector31 vVector) {return tVector31(vVector.x+x, vVector.y+y, vVector.z+z);}
	// overload - operator that we easier can subtract vectors
	tVector31 operator-(tVector31 vVector) {return tVector31(x-vVector.x, y-vVector.y, z-vVector.z);}
	// overload * operator that we easier can multiply by scalars
	tVector31 operator*(float number)	 {return tVector31(x*number, y*number, z*number);}
	// overload / operator that we easier can divide by a scalar
	tVector31 operator/(float number)	 {return tVector31(x/number, y/number, z/number);}
	
	float x, y, z;						// 3D vector coordinates
}tVector31;

//////////////////////////////////////
//The tVector2 Struct
//////////////////////////////////////											
struct tVector21 
{
	float x, y;							// 2D vector coordinates
};





//typedef unsigned short BYTE;

// Primary Chunk, at the beginning of each file
#define PRIMARY       0x4D4D

// Main Chunks
#define OBJECTINFO    0x3D3D				 
#define VERSION       0x0002				
#define EDITKEYFRAME  0xB000				

// Sub defines of OBJECTINFO
#define MATERIAL	  0xAFFF				
#define OBJECT		  0x4000				

// Sub defines of MATERIAL
#define MATNAME       0xA000				
#define MATDIFFUSE    0xA020				
#define MATMAP        0xA200				
#define MATMAPFILE    0xA300				

#define OBJECT_MESH   0x4100				

// Sub defines of OBJECT_MESH
#define OBJECT_VERTICES     0x4110			
#define OBJECT_FACES		0x4120			
#define OBJECT_MATERIAL		0x4130			
#define OBJECT_UV			0x4140			



//////////////////////////////////////
//The tFace Struct
//////////////////////////////////////
struct tFace
{
	int vertIndex[3];							
	int coordIndex[3];							
};

//////////////////////////////////////
//The tMaterialInfo Struct
//////////////////////////////////////
struct tMaterialInfo
{
	char  strName[255];							
	char  strFile[255];							
	BYTE  color[3];								
	int   texureId;								
	float uTile;								
	float vTile;								
	float uOffset;								
	float vOffset;									
};

//////////////////////////////////////
//The t3DObject Struct
//////////////////////////////////////
struct t3DObject 
{
	int  numOfVerts;			
	int  numOfFaces;			
	int  numTexVertex;			
	int  materialID;			
	//bool bHasTexture;			
	char strName[255];			
	UINT      *pIndices;		
	tVector31  *pVerts;			
	tVector31  *pNormals;		
	tVector21  *pTexVerts;		
	tFace *pFaces;				
};

//////////////////////////////////////
//The t3DModel Struct
//////////////////////////////////////
struct t3DModel 
{
	int numOfObjects;							
	int numOfMaterials;							
	vector<tMaterialInfo> pMaterials;			
	vector<t3DObject> pObject;					
};





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Here is our structure for our 3DS indicies (since .3DS stores 4 unsigned shorts)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct tIndices {							

	unsigned short a, b, c, bVisible;		
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This holds the chunk info
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct tChunk
{
	unsigned short int ID;					
	unsigned int length;					
	unsigned int bytesRead;					
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This class handles all of the loading code
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CLoad3DS
{
public:
	CLoad3DS();								

	bool Import3DS(t3DModel *pModel, char *strFileName);

private:
	int GetString(char *);

	void ReadChunk(tChunk *);

	void ProcessNextChunk(t3DModel *pModel, tChunk *);

	void ProcessNextObjectChunk(t3DModel *pModel, t3DObject *pObject, tChunk *);

	void ProcessNextMaterialChunk(t3DModel *pModel, tChunk *);

	void ReadColorChunk(tMaterialInfo *pMaterial, tChunk *pChunk);

	void ReadVertices(t3DObject *pObject, tChunk *);

	void ReadVertexIndices(t3DObject *pObject, tChunk *);

	void ReadUVCoordinates(t3DObject *pObject, tChunk *);

	void ReadObjectMaterial(t3DModel *pModel, t3DObject *pObject, tChunk *pPreviousChunk);
	
	void ComputeNormals(t3DModel *pModel);

	void CleanUp();
	
	FILE *m_FilePointer;
	
	tChunk *m_CurrentChunk;
	tChunk *m_TempChunk;
};

// This returns the absolute value of num - a simple if/else check
float absolute(float num);

//	This returns a perpendicular vector from 2 given vectors by taking the cross product.
tVector31 Cross(tVector31 vVector1, tVector31 vVector2);

// This returns the dot product between 2 vectors
float Dot(tVector31 vVector1, tVector31 vVector2);

//	This returns a normalize vector (A vector exactly of length 1)
tVector31 Normalize(tVector31 vNormal);

//	This returns the normal of a polygon (The direction the polygon is facing)
tVector31 Normal(tVector31 vTriangle[]);

//	This returns the magnitude of a normal (or any other vector)
float Magnitude(tVector31 vNormal);




/////////////////////////////////////////////////////////////////////////////////////////////////
//										 ABSOLUTE		returnes the absolute value
/////////////////////////////////////////////////////////////////////////////////////////////////
float Absolute(float num)
{
	if(num < 0) return (0 - num);
	return num;	
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//										 CROSS			returnes the cross product
/////////////////////////////////////////////////////////////////////////////////////////////////
tVector31 Cross(tVector31 vVector1, tVector31 vVector2)
{
	tVector31 vNormal;									
	
	vNormal.x = ((vVector1.y * vVector2.z) - (vVector1.z * vVector2.y));
	vNormal.y = ((vVector1.z * vVector2.x) - (vVector1.x * vVector2.z));
	vNormal.z = ((vVector1.x * vVector2.y) - (vVector1.y * vVector2.x));
	
	return vNormal;										
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//										 DOT			calculates the dot product
/////////////////////////////////////////////////////////////////////////////////////////////////
float Dot(tVector31 vVector1, tVector31 vVector2) 
{
	return ( (vVector1.x * vVector2.x) + (vVector1.y * vVector2.y) + (vVector1.z * vVector2.z) );
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//										 NORMALIZE		returnes the vector normalized
/////////////////////////////////////////////////////////////////////////////////////////////////
tVector31 Normalize(tVector31 vNormal)
{
	float magnitude = Magnitude(vNormal);				
	
	vNormal.x /= magnitude;								
	vNormal.y /= magnitude;								
	vNormal.z /= magnitude;								
	
	return vNormal;							
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//										 NORMAL			returnes the normal of a triangle
/////////////////////////////////////////////////////////////////////////////////////////////////
tVector31 Normal(tVector31 vTriangle[])					
{	
	tVector31 vVector1 = vTriangle[2] - vTriangle[0];
	tVector31 vVector2 = vTriangle[1] - vTriangle[0];
	tVector31 vNormal = Cross(vVector1, vVector2);		
	vNormal = Normalize(vNormal);						
	
	return vNormal;										
}



/////////////////////////////////////////////////////////////////////////////////////////////////
//										 MAGNITUDE		magnitude of a normal or vector
/////////////////////////////////////////////////////////////////////////////////////////////////
float Magnitude(tVector31 vNormal)
{
	return (float)sqrt( (vNormal.x * vNormal.x) + (vNormal.y * vNormal.y) + (vNormal.z * vNormal.z) );
}



//-------------------------------- CLOADS3DS ------------------------------------
//	This constructor initializes the tChunk data
//-------------------------------- CLOADS3DS ------------------------------------

CLoad3DS::CLoad3DS()
{
	m_CurrentChunk = new tChunk;				 
	m_TempChunk    = new tChunk;					
}

//---------------------------------- IMPORT 3DS ----------------------------------
//		This is called by the client to open the .3ds file, read it, then clean up
//---------------------------------- IMPORT 3DS -----------------------------------

bool CLoad3DS::Import3DS(t3DModel *pModel, char *strFileName)
{
	char strMessage[255] = {0};
	
	m_FilePointer = fopen(strFileName, "rb");
	
	if(!m_FilePointer) 
	{
		sprintf(strMessage, "Unable to find the file: %s!", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		return false;
	}
	
	ReadChunk(m_CurrentChunk);
	
	if (m_CurrentChunk->ID != PRIMARY)
	{
		sprintf(strMessage, "Unable to load PRIMARY chuck from file: %s!", strFileName);
		MessageBox(NULL, strMessage, "Error", MB_OK);
		return false;
	}
	
	ProcessNextChunk(pModel, m_CurrentChunk);
	
	ComputeNormals(pModel);
	
	CleanUp();
	
	return 0;
}

//---------------------------------- CLEAN UP ----------------------------------
//		This function cleans up our allocated memory and closes the file
//---------------------------------- CLEAN UP ----------------------------------

void CLoad3DS::CleanUp()
{
	fclose(m_FilePointer);						 
	delete m_CurrentChunk;						
	delete m_TempChunk;							
}


//---------------------------------- PROCESS NEXT CHUNK-----------------------------------
//	This function reads the main sections of the .3DS file, then dives deeper with recursion
//---------------------------------- PROCESS NEXT CHUNK-----------------------------------

void CLoad3DS::ProcessNextChunk(t3DModel *pModel, tChunk *pPreviousChunk)
{
	t3DObject newObject = {0};					 
	tMaterialInfo newTexture = {0};				
	unsigned short version = 0;					
	int buffer[50000] = {0};					
	
	m_CurrentChunk = new tChunk;				
	
	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(m_CurrentChunk);
		
		switch (m_CurrentChunk->ID)
		{
		case VERSION:							
			
			m_CurrentChunk->bytesRead += fread(&version, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			
			if (version > 0x03)
				MessageBox(NULL, "This 3DS file is over version 3 so it may load incorrectly", "Warning", MB_OK);
			break;
			
		case OBJECTINFO:						
			ReadChunk(m_TempChunk);
			
			m_TempChunk->bytesRead += fread(&version, 1, m_TempChunk->length - m_TempChunk->bytesRead, m_FilePointer);
			
			m_CurrentChunk->bytesRead += m_TempChunk->bytesRead;
			
			ProcessNextChunk(pModel, m_CurrentChunk);
			break;
			
		case MATERIAL:						
			pModel->numOfMaterials++;
			
			pModel->pMaterials.push_back(newTexture);
			
			ProcessNextMaterialChunk(pModel, m_CurrentChunk);
			break;
			
		case OBJECT:							
			pModel->numOfObjects++;
			
			pModel->pObject.push_back(newObject);
			
			memset(&(pModel->pObject[pModel->numOfObjects - 1]), 0, sizeof(t3DObject));
			
			m_CurrentChunk->bytesRead += GetString(pModel->pObject[pModel->numOfObjects - 1].strName);
			
			ProcessNextObjectChunk(pModel, &(pModel->pObject[pModel->numOfObjects - 1]), m_CurrentChunk);
			break;
			
		case EDITKEYFRAME:
			
			m_CurrentChunk->bytesRead += fread(buffer, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
			
		default: 
			
			m_CurrentChunk->bytesRead += fread(buffer, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
		}
		
		pPreviousChunk->bytesRead += m_CurrentChunk->bytesRead;
	}
	
	delete m_CurrentChunk;
	m_CurrentChunk = pPreviousChunk;
}


//---------------------------------- PROCESS NEXT OBJECT CHUNK -----------------------------------
//		This function handles all the information about the objects in the file
//---------------------------------- PROCESS NEXT OBJECT CHUNK -----------------------------------

void CLoad3DS::ProcessNextObjectChunk(t3DModel *pModel, t3DObject *pObject, tChunk *pPreviousChunk)
{
	int buffer[50000] = {0};					
	
	m_CurrentChunk = new tChunk;
	
	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(m_CurrentChunk);
		
		switch (m_CurrentChunk->ID)
		{
		case OBJECT_MESH:		
			ProcessNextObjectChunk(pModel, pObject, m_CurrentChunk);
			break;
			
		case OBJECT_VERTICES:			 
			ReadVertices(pObject, m_CurrentChunk);
			break;
			
		case OBJECT_FACES:				 
			ReadVertexIndices(pObject, m_CurrentChunk);
			break;
			
		case OBJECT_MATERIAL:			 
			ReadObjectMaterial(pModel, pObject, m_CurrentChunk);			
			break;
			
		case OBJECT_UV:					
			ReadUVCoordinates(pObject, m_CurrentChunk);
			break;
			
		default: 
			m_CurrentChunk->bytesRead += fread(buffer, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
		}
		
		pPreviousChunk->bytesRead += m_CurrentChunk->bytesRead;
	}
	
	delete m_CurrentChunk;
	m_CurrentChunk = pPreviousChunk;
}


//---------------------------------- PROCESS NEXT MATERIAL CHUNK -----------------------------------
//	This function handles all the information about the material (Texture)
//---------------------------------- PROCESS NEXT MATERIAL CHUNK -----------------------------------

void CLoad3DS::ProcessNextMaterialChunk(t3DModel *pModel, tChunk *pPreviousChunk)
{
	int buffer[50000] = {0};					  
	m_CurrentChunk = new tChunk;
	
	while (pPreviousChunk->bytesRead < pPreviousChunk->length)
	{
		ReadChunk(m_CurrentChunk);
		
		switch (pModel, m_CurrentChunk->ID)
		{
		case MATNAME:						 
			m_CurrentChunk->bytesRead += fread(pModel->pMaterials[pModel->numOfMaterials - 1].strName, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
			
		case MATDIFFUSE:					 
			ReadColorChunk(&(pModel->pMaterials[pModel->numOfMaterials - 1]), m_CurrentChunk);
			break;
			
		case MATMAP:						 
			ProcessNextMaterialChunk(pModel, m_CurrentChunk);
			break;
			
		case MATMAPFILE:						 
			m_CurrentChunk->bytesRead += fread(pModel->pMaterials[pModel->numOfMaterials - 1].strFile, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
			
		default:  
			m_CurrentChunk->bytesRead += fread(buffer, 1, m_CurrentChunk->length - m_CurrentChunk->bytesRead, m_FilePointer);
			break;
		}
		pPreviousChunk->bytesRead += m_CurrentChunk->bytesRead;
	}
	
	delete m_CurrentChunk;
	m_CurrentChunk = pPreviousChunk;
}

//---------------------------------- READ CHUNK ----------------------------------
//		This function reads in a chunk ID and it's length in bytes
//---------------------------------- READ CHUNK -----------------------------------

void CLoad3DS::ReadChunk(tChunk *pChunk)
{
	pChunk->bytesRead = fread(&pChunk->ID, 1, 2, m_FilePointer);
	
	pChunk->bytesRead += fread(&pChunk->length, 1, 4, m_FilePointer);
}

//---------------------------------- GET STRING -----------------------------------
//		This function reads in a string of characters
//---------------------------------- GET STRING -----------------------------------

int CLoad3DS::GetString(char *pBuffer)
{
	int index = 0;
	
	fread(pBuffer, 1, 1, m_FilePointer);
	
	while (*(pBuffer + index++) != 0) 
	{
		fread(pBuffer + index, 1, 1, m_FilePointer);
	}
	
	return strlen(pBuffer) + 1;
}


//---------------------------------- READ COLOR ----------------------------------
//		This function reads in the RGB color data
//---------------------------------- READ COLOR -----------------------------------

void CLoad3DS::ReadColorChunk(tMaterialInfo *pMaterial, tChunk *pChunk)
{
	ReadChunk(m_TempChunk);
	m_TempChunk->bytesRead += fread(pMaterial->color, 1, m_TempChunk->length - m_TempChunk->bytesRead, m_FilePointer);
	pChunk->bytesRead += m_TempChunk->bytesRead;
}


//---------------------------------- READ VERTEX INDECES ----------------------------------
//		This function reads in the indices for the vertex array
//---------------------------------- READ VERTEX INDECES -----------------------------------

void CLoad3DS::ReadVertexIndices(t3DObject *pObject, tChunk *pPreviousChunk)
{
	unsigned short index = 0;					 
	pPreviousChunk->bytesRead += fread(&pObject->numOfFaces, 1, 2, m_FilePointer);
	
	pObject->pFaces = new tFace [pObject->numOfFaces];
	memset(pObject->pFaces, 0, sizeof(tFace) * pObject->numOfFaces);
	
	
	for(int i = 0; i < pObject->numOfFaces; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			pPreviousChunk->bytesRead += fread(&index, 1, sizeof(index), m_FilePointer);
			
			if(j < 3)
			{
				pObject->pFaces[i].vertIndex[j] = index;
			}
		}
	}
}


//---------------------------------- READ UV COORDINATES -----------------------------------
//		This function reads in the UV coordinates for the object
//---------------------------------- READ UV COORDINATES -----------------------------------

void CLoad3DS::ReadUVCoordinates(t3DObject *pObject, tChunk *pPreviousChunk)
{
	pPreviousChunk->bytesRead += fread(&pObject->numTexVertex, 1, 2, m_FilePointer);
	
	pObject->pTexVerts = new tVector21 [pObject->numTexVertex];
	
	pPreviousChunk->bytesRead += fread(pObject->pTexVerts, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
}


//---------------------------------- READ VERTICES -----------------------------------
//	This function reads in the vertices for the object
//---------------------------------- READ VERTICES -----------------------------------

void CLoad3DS::ReadVertices(t3DObject *pObject, tChunk *pPreviousChunk)
{ 
	pPreviousChunk->bytesRead += fread(&(pObject->numOfVerts), 1, 2, m_FilePointer);
	
	pObject->pVerts = new tVector31 [pObject->numOfVerts];
	memset(pObject->pVerts, 0, sizeof(tVector31) * pObject->numOfVerts);
	
	pPreviousChunk->bytesRead += fread(pObject->pVerts, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
}


//---------------------------------- READ OBJECT MATERIAL -----------------------------------
//	This function reads in the material name assigned to the object and sets the materialID
//---------------------------------- READ OBJECT MATERIAL -----------------------------------

void CLoad3DS::ReadObjectMaterial(t3DModel *pModel, t3DObject *pObject, tChunk *pPreviousChunk)
{
	char strMaterial[255] = {0};			
	int buffer[50000] = {0};				
	
	pPreviousChunk->bytesRead += GetString(strMaterial);
	
	for(int i = 0; i < pModel->numOfMaterials; i++)
	{
		if(strcmp(strMaterial, pModel->pMaterials[i].strName) == 0)
		{
			pObject->materialID = i;
			
			if(strlen(pModel->pMaterials[i].strFile) > 0) {
				
				//pObject->bHasTexture = true;
			}	
			break;
		}
	}
	
	pPreviousChunk->bytesRead += fread(buffer, 1, pPreviousChunk->length - pPreviousChunk->bytesRead, m_FilePointer);
}			


#define Mag(Normal) (sqrt(Normal.x*Normal.x + Normal.y*Normal.y + Normal.z*Normal.z))

tVector31 Vector(tVector31 vPoint1, tVector31 vPoint2)
{
	tVector31 vVector;							
	
	vVector.x = vPoint1.x - vPoint2.x;			
	vVector.y = vPoint1.y - vPoint2.y;			
	vVector.z = vPoint1.z - vPoint2.z;			
	
	return vVector;								
}

tVector31 AddVector(tVector31 vVector1, tVector31 vVector2)
{
	tVector31 vResult;							
	
	vResult.x = vVector2.x + vVector1.x;		
	vResult.y = vVector2.y + vVector1.y;		
	vResult.z = vVector2.z + vVector1.z;		
	
	return vResult;								
}

tVector31 DivideVectorByScaler(tVector31 vVector1, float Scaler)
{
	tVector31 vResult;							
	
	vResult.x = vVector1.x / Scaler;			
	vResult.y = vVector1.y / Scaler;			
	vResult.z = vVector1.z / Scaler;			
	
	return vResult;								
}

/*
// I have this function in my 3Dmath file
tVector31 Normalize(tVector31 vNormal)
{
	double Magnitude;							
	
	Magnitude = Mag(vNormal);					
	
	vNormal.x /= (float)Magnitude;				
	vNormal.y /= (float)Magnitude;				
	vNormal.z /= (float)Magnitude;				
	
	return vNormal;								
}

*/

//---------------------------------- COMPUTER NORMALS -----------------------------------
//		This function computes the normals and vertex normals of the objects
//---------------------------------- COMPUTER NORMALS -----------------------------------

void CLoad3DS::ComputeNormals(t3DModel *pModel)
{
	tVector31 vVector1, vVector2, vNormal, vPoly[3];
	
	if(pModel->numOfObjects <= 0)
		return;
	
	for(int index = 0; index < pModel->numOfObjects; index++)
	{
		t3DObject *pObject = &(pModel->pObject[index]);
		
		tVector31 *pNormals		= new tVector31 [pObject->numOfFaces];
		tVector31 *pTempNormals	= new tVector31 [pObject->numOfFaces];
		pObject->pNormals		= new tVector31 [pObject->numOfVerts];
		
		for(int i=0; i < pObject->numOfFaces; i++)
		{												
			vPoly[0] = pObject->pVerts[pObject->pFaces[i].vertIndex[0]];
			vPoly[1] = pObject->pVerts[pObject->pFaces[i].vertIndex[1]];
			vPoly[2] = pObject->pVerts[pObject->pFaces[i].vertIndex[2]];
			
			
			vVector1 = vPoly[0] - vPoly[2];				
			vVector2 = vPoly[2] - vPoly[1];				
			
			vNormal  = Cross(vVector1, vVector2);		
			pTempNormals[i] = vNormal;					
			vNormal  = Normalize(vNormal);				
			
			pNormals[i] = vNormal;						
		}
		
		
		tVector31 vSum(0.0, 0.0, 0.0);
		tVector31 vZero = vSum;
		int shared=0;
		
		for (i = 0; i < pObject->numOfVerts; i++)			
		{
			for (int j = 0; j < pObject->numOfFaces; j++)	
			{												
				if (pObject->pFaces[j].vertIndex[0] == i || 
					pObject->pFaces[j].vertIndex[1] == i || 
					pObject->pFaces[j].vertIndex[2] == i)
				{
					vSum = vSum + pTempNormals[j];			
					shared++;								
				}
			}      
			
			pObject->pNormals[i] = DivideVectorByScaler(vSum, float(-shared));
			
			pObject->pNormals[i] = Normalize(pObject->pNormals[i]);	
			
			vSum = vZero;									 
			shared = 0;										
		}
		
		delete [] pTempNormals;
		delete [] pNormals;
	}
}









//////////////////////////////////////
//The 3dsLoader Class
//////////////////////////////////////
class C3dsLoader
{
	public:
		CLoad3DS mLoad3ds;						
		t3DModel m3DModel;	

		void Init_3ds(char* filename);
		void Render_3ds();
		void Unload_3ds();
};




/////////////////////////////////////////////////////////////////////////////////////////////////
//										 INIT 3DS
/////////////////////////////////////////////////////////////////////////////////////////////////
void C3dsLoader::Init_3ds(char* filename)
{
	mLoad3ds.Import3DS(&m3DModel, filename);						
	
	for(int i = 0; i < m3DModel.numOfMaterials; i++)				
	{
		if(strlen(m3DModel.pMaterials[i].strFile) > 0)				
		{
//			Texture_3ds(TextureArray3ds, m3DModel.pMaterials[i].strFile, i);			
		}
		
		m3DModel.pMaterials[i].texureId = i;						
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//										RENDER 3DS
/////////////////////////////////////////////////////////////////////////////////////////////////
void C3dsLoader::Render_3ds()
{
	int index;
	t3DObject *pObject;
	glBegin(GL_TRIANGLES);											
	for(int i = 0; i < m3DModel.numOfObjects; i++)
	{
		if(m3DModel.pObject.size() <= 0) break;						
		pObject = &m3DModel.pObject[i];					
		for(int j = 0; j < pObject->numOfFaces; j++)
		{
			for(int whichVertex = 0; whichVertex < 3; whichVertex++)
			{
				index = pObject->pFaces[j].vertIndex[whichVertex];
				glNormal3f(pObject->pNormals[ index ].x, pObject->pNormals[ index ].y, pObject->pNormals[ index ].z);
				glTexCoord2f(pObject->pTexVerts[ index ].x, pObject->pTexVerts[ index ].y);
				glVertex3f(pObject->pVerts[ index ].x, pObject->pVerts[ index ].y, pObject->pVerts[ index ].z);
			}
		}
	}
	glEnd();
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//										TEXTURE 3DS			jpeg or bmp
/////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////
//										UNLOAD 3DS
/////////////////////////////////////////////////////////////////////////////////////////////////
void C3dsLoader::Unload_3ds()
{
	for(int i = 0; i < m3DModel.numOfObjects; i++)	
	{
		delete [] m3DModel.pObject[i].pFaces;
		delete [] m3DModel.pObject[i].pNormals;
		delete [] m3DModel.pObject[i].pVerts;
		delete [] m3DModel.pObject[i].pTexVerts;
	}
}
#endif

//Ronny André Reierstad
//www.morrowland.com
//apron@morrowland.com
