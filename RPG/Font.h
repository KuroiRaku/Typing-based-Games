#include "glad/glad.h"
#include <glm\glm.hpp>
#include <string>
#include <vector>
#include "stb_image.h"
#include <map>

class Font {
private:
	//This tag holds information on how the font was generated.
	struct Info {
		//This is the name of the true type font.
		std::string name;
		//The size of the true type font.
		unsigned int size;
		//The font is bold.
		bool bold;
		//The font is italic.
		bool italic;
		/*char set and Unicode goes here*/
		//The font height stretch in percentage. 100% means no stretch.
		int stretchH;
		//Set to 1 if smoothing was turned on.
		bool smooth;
		//The supersampling level used. 1 means no supersampling was used.
		int aa;
		//The padding for each character (up, right, down, left).
		int padding[4];
		//The spacing for each character (horizontal, vertical).
		int spacing[2];
		//The outline thickness for the characters.
		int outline;
	};

	//This tag holds information common to all characters.
	struct Common {
		//This is the distance in pixels between each line of text.
		unsigned int lineHeight;
		//The number of pixels from the absolute top of the line to the base of the characters.
		unsigned int base;
		//The width of the texture, normally used to scale the x pos of the character image.
		unsigned int scaleW;
		//The height of the texture, normally used to scale the y pos of the character image.
		unsigned int scaleH;
		//The number of texture pages included in the font.
		unsigned int pages;
		//Set to 1 if the monochrome characters have been packed into each of the texture channels. In this case alphaChannel describes what is stored in each channel.
		bool packed;
		//Set to 0 if the channel holds the glyph data, 1 if it holds the outline, 2 if it holds the glyph and the outline, 3 if its set to zero, and 4 if its set to one.
		unsigned int alphaChannel;
		//Set to 0 if the channel holds the glyph data, 1 if it holds the outline, 2 if it holds the glyph and the outline, 3 if its set to zero, and 4 if its set to one.
		unsigned int redChannel;
		//Set to 0 if the channel holds the glyph data, 1 if it holds the outline, 2 if it holds the glyph and the outline, 3 if its set to zero, and 4 if its set to one.
		unsigned int greenChannel;
		//Set to 0 if the channel holds the glyph data, 1 if it holds the outline, 2 if it holds the glyph and the outline, 3 if its set to zero, and 4 if its set to one.
		unsigned int blueChannel;
	};

	//This tag gives the name of a texture file. There is one for each page in the font.
	struct Page {
		//The page id.
		unsigned int id;
		//The texture file name.
		std::string fileName;

		//ID of GL texture
		GLuint m_TexId = 0;
	};

	//This tag describes on character in the font. There is one for each included character in the font.
	struct Character {
		//The character id.
		unsigned int index;
		//The left position of the character image in the texture.
		unsigned int xCoord;
		//The top position of the character image in the texture.
		unsigned int yCoord;
		//The width of the character image in the texture.
		unsigned int width;
		//The height of the character image in the texture.
		unsigned int height;
		//How much the current position should be offset when copying the image from the texture to the screen.
		int xOffset;
		//How much the current position should be offset when copying the image from the texture to the screen.
		int yOffset;
		//How much the current position should be advanced after drawing the character.
		unsigned int xAdvance;
		//The texture page where the character image is found.
		unsigned int page;
		//The texture channel where the character image is found (1 = blue, 2 = green, 4 = red, 8 = alpha, 15 = all channels).
		unsigned int channel;

		//kerning data for this character
		//The kerning information is used to adjust the distance between certain characters, e.g. some characters should be placed closer to each other than others.
		//<int, int>
		//second character, amount
		std::map<int, int> kerning;
	};

	////The kerning information is used to adjust the distance between certain characters, e.g. some characters should be placed closer to each other than others.
	//struct Kerning {
	//	//The first character id.
	//	unsigned int first;
	//	//The second character id.
	//	unsigned int second;
	//	//How much the x position should be adjusted when drawing the second character immediately following the first.
	//	int amount;
	//};

public:
	Font(const char* const a_FileLocation);
	~Font();

	void draw(const char* const a_Letters, int const a_X, int const a_Y, float const a_Scale = 1.0f, glm::vec3 a_Color = glm::vec3(1.0f, 1.0f, 1.0f));

private:

	std::string m_FileName;

	Info m_Info;
	Common m_Common;
	std::vector<Page> m_Pages;
	std::map<int, Character> m_Chars;
	//std::vector<Kerning> m_Kernings;

	int getsSubString(const std::string* const a_Input, std::string* a_Output, int a_Start, char a_Prefix = '=', char a_Suffix = ' ');

	void loadFile(const char* const a_FileName);
	void loadTextures();
	void genVertex();

	GLuint VAO, VBO;

};


