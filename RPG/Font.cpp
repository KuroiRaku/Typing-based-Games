
#define STB_IMAGE_IMPLEMENTATION
#include "Font.h"
#include <fstream>
#include <iostream>
#include <stdio.h>




using namespace std;

Font::Font(const char* const a_FileLocation) {
	m_FileName = a_FileLocation;
	loadFile(a_FileLocation);
	loadTextures();
	genVertex();
}

void Font::loadFile(const char* const a_FileName) {
	string line;
	ifstream read = ifstream(a_FileName);

	bool completed = true;
	int lineNum = 0;
	int stage = 0;

	//when loading a bunch of information relating to 
	int currentLeft = 0;

	if (read.is_open()) {
		while (getline(read, line)) {
			lineNum++;

			string temp;
			unsigned int end = 0;

			if (stage == 0) {//info
				//face
				end = getsSubString(&line, &temp, end, '"', '"');
				m_Info.name = temp;

				//size
				end = getsSubString(&line, &temp, end);
				m_Info.size = stoi(temp, nullptr, 10);

				//bold
				end = getsSubString(&line, &temp, end);
				m_Info.bold = stoi(temp, nullptr, 10) ? true : false;

				//char set
				//unused
				end = getsSubString(&line, &temp, end, '"', '"');

				//unicode
				//unused
				end = getsSubString(&line, &temp, end);

				//stretch
				end = getsSubString(&line, &temp, end);
				m_Info.stretchH = stoi(temp, nullptr, 10);

				//smooth
				end = getsSubString(&line, &temp, end);
				m_Info.smooth = stoi(temp, nullptr, 10);

				//aa
				end = getsSubString(&line, &temp, end);
				m_Info.aa = stoi(temp, nullptr, 10);

				//padding
				end = getsSubString(&line, &temp, end, '=', ',');
				m_Info.padding[0] = stoi(temp, nullptr, 10);
				end = getsSubString(&line, &temp, end, ',', ',');
				m_Info.padding[1] = stoi(temp, nullptr, 10);
				end = getsSubString(&line, &temp, end, ',', ',');
				m_Info.padding[2] = stoi(temp, nullptr, 10);
				end = getsSubString(&line, &temp, end, ',', ' ');
				m_Info.padding[3] = stoi(temp, nullptr, 10);

				//spacing
				end = getsSubString(&line, &temp, end, '=', ',');
				m_Info.spacing[0] = stoi(temp, nullptr, 10);
				end = getsSubString(&line, &temp, end, ',', ' ');
				m_Info.spacing[1] = stoi(temp, nullptr, 10);

				//outline
				int start = line.find_last_of('=', line.length()) + 1;
				temp = line.substr(start, end - line.length());
				m_Info.outline = stoi(temp, nullptr, 10);

				stage++;
			}
			else
				if (stage == 1) {//common
					//line height
					end = getsSubString(&line, &temp, end);
					m_Common.lineHeight = stoi(temp, nullptr, 10);

					//base
					end = getsSubString(&line, &temp, end);
					m_Common.base = stoi(temp, nullptr, 10);

					//scaleW
					end = getsSubString(&line, &temp, end);
					m_Common.scaleW = stoi(temp, nullptr, 10);

					//scaleH
					end = getsSubString(&line, &temp, end);
					m_Common.scaleH = stoi(temp, nullptr, 10);

					//pages
					end = getsSubString(&line, &temp, end);
					currentLeft = stoi(temp, nullptr, 10);
					m_Common.pages = currentLeft;

					//packed
					end = getsSubString(&line, &temp, end);
					m_Common.packed = stoi(temp, nullptr, 10);

					//color channels
					//a
					end = getsSubString(&line, &temp, end);
					m_Common.alphaChannel = stoi(temp, nullptr, 10);
					//r
					end = getsSubString(&line, &temp, end);
					m_Common.redChannel = stoi(temp, nullptr, 10);
					//g
					end = getsSubString(&line, &temp, end);
					m_Common.greenChannel = stoi(temp, nullptr, 10);
					//b
					int start = line.find_last_of('=', line.length()) + 1;
					temp = line.substr(start, end - line.length());
					m_Common.blueChannel = stoi(temp, nullptr, 10);

					stage++;

				}
				else
					if (stage == 2) {//pages
						Page page;

						//id
						end = getsSubString(&line, &temp, end);
						page.id = stoi(temp, nullptr, 10);

						//file name/texture name
						end = getsSubString(&line, &temp, end, '"', '"');
						page.fileName = temp;

						//add to vector
						m_Pages.push_back(page);

						//one less of this stage to do
						currentLeft--;
						if (currentLeft <= 0) {
							stage++;
						}

					}
					else
						if (stage == 3) {//char amount

							int start = line.find_last_of('=', line.length()) + 1;
							temp = line.substr(start, end - line.length());
							currentLeft = stoi(temp, nullptr, 10);

							stage++;
						}
						else
							if (stage == 4) {//char area
								Character letter;

								//id
								end = getsSubString(&line, &temp, end);
								letter.index = stoi(temp, nullptr, 10);

								//x
								end = getsSubString(&line, &temp, end);
								letter.xCoord = stoi(temp, nullptr, 10);

								//y
								end = getsSubString(&line, &temp, end);
								letter.yCoord = stoi(temp, nullptr, 10);

								//width
								end = getsSubString(&line, &temp, end);
								letter.width = stoi(temp, nullptr, 10);

								//height
								end = getsSubString(&line, &temp, end);
								letter.height = stoi(temp, nullptr, 10);

								//xOffset
								end = getsSubString(&line, &temp, end);
								letter.xOffset = stoi(temp, nullptr, 10);

								//yOffset
								end = getsSubString(&line, &temp, end);
								letter.yOffset = stoi(temp, nullptr, 10);

								//xAdvance
								end = getsSubString(&line, &temp, end);
								letter.xAdvance = stoi(temp, nullptr, 10);

								//page
								end = getsSubString(&line, &temp, end);
								letter.page = stoi(temp, nullptr, 10);

								//channel
								int start = line.find_last_of('=', line.length()) + 1;
								temp = line.substr(start, end - line.length());
								letter.channel = stoi(temp, nullptr, 10);


								//add to map
								m_Chars[letter.index] = letter;

								//one less of this stage to do
								currentLeft--;
								if (currentLeft <= 0) {
									stage++;
								}
							}
							else
								if (stage == 5) {//kerning amount
									int start = line.find_last_of('=', line.length()) + 1;
									temp = line.substr(start, end - line.length());
									currentLeft = stoi(temp, nullptr, 10);

									stage++;
								}
								else
									if (stage == 6) {//kerning area
										int first, second, amount;

										//left character
										end = getsSubString(&line, &temp, end);
										first = stoi(temp, nullptr, 10);

										//right character
										end = getsSubString(&line, &temp, end);
										second = stoi(temp, nullptr, 10);

										//amount
										int start = line.find_last_of('=', line.length()) + 1;
										temp = line.substr(start, end - line.length());
										amount = stoi(temp, nullptr, 10);


										//add to map
										m_Chars.at(first).kerning[second] = amount;

										//one less of this stage to do
										currentLeft--;
										if (currentLeft <= 0) {
											stage++;
										}

									}

		}

		read.close();
	}
	else {
		completed = false;
	}

	if (!completed) {
		cout << "failed at reading font file: " << a_FileName << " stuck at line: " << lineNum << endl;
	}
}

void Font::loadTextures() {
	string baseFolder = m_FileName.substr(0, m_FileName.find_last_of('/', m_FileName.length()) + 1);

	for (int i = 0; i < m_Pages.size(); i++) {
		string filename = baseFolder + m_Pages[i].fileName;

		
		GLuint* textureID = &m_Pages[i].m_TexId;

		if (&textureID != 0) {
			glDeleteTextures(1, textureID);
		}

		glGenTextures(1, textureID);

		int width, height, bpp;
		unsigned char* image = stbi_load(filename.c_str(), &width, &height, &bpp, 3);

		glBindTexture(GL_TEXTURE_2D, *textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, 0);
		
		
	}
}

void Font::genVertex() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

Font::~Font() {
	for (int i = 0; i < m_Pages.size(); i++) {
		glDeleteTextures(1, &m_Pages[i].m_TexId);
		m_Pages[i].m_TexId = 0;
	}

	if (VAO != 0) {
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
}

void Font::draw(const char* const a_Letters, int const a_X, int const a_Y, float const a_Scale, glm::vec3 a_Color) {
	/*
	Shader::setUniform("Color", a_Color.x, a_Color.y, a_Color.z);
	*/

	glActiveTexture(GL_TEXTURE0);
	/*
	Shader::setUniform("image", 0);
	*/
	glBindVertexArray(this->VAO);

	float imgHeight = m_Common.scaleH;
	float imgWidth = m_Common.scaleW;

	float xPos = a_X;
	float yPos = a_Y;

	int index = 0;

	while (a_Letters[index] != '\0') {

		//text placement/render
		auto iteratorLetter = m_Chars.find(a_Letters[index]);
		if (iteratorLetter != m_Chars.end()) {
			Character letter = iteratorLetter->second;

			float sizeWidth = letter.width * a_Scale;
			float sizeHeight = letter.height * a_Scale;

			float uvStartX = letter.xCoord / imgWidth;
			float uvStartY = letter.yCoord / imgHeight;

			float uvWidth = letter.width / imgWidth;
			float uvHeight = letter.height / imgHeight;

			float xOffset = letter.xOffset * a_Scale;
			float yOffset = letter.yOffset * a_Scale;

			//xPos += xOffset;

			GLfloat verts[6][4] = {
				//triangle 1
				{ xPos + xOffset + 0			,yPos + yOffset + 0			,uvStartX + 0.0f	,uvStartY + 0.0f },
				{ xPos + xOffset + sizeWidth	,yPos + yOffset + sizeHeight	,uvStartX + uvWidth	,uvStartY + uvHeight },
				{ xPos + xOffset + sizeWidth	,yPos + yOffset + 0			,uvStartX + uvWidth	,uvStartY + 0.0f },

				//triangle 2						
				{ xPos + xOffset + 0			,yPos + yOffset + 0			,uvStartX + 0.0f	,uvStartY + 0.0f },
				{ xPos + xOffset + 0			,yPos + yOffset + sizeHeight	,uvStartX + 0.0f	,uvStartY + uvHeight },
				{ xPos + xOffset + sizeWidth	,yPos + yOffset + sizeHeight	,uvStartX + uvWidth	,uvStartY + uvHeight },
			};

			xPos += letter.xAdvance * a_Scale;

			if (a_Letters[index + 1] != '\0') {
				auto num = letter.kerning.find(a_Letters[index + 1]);
				if (num != letter.kerning.end()) {
					xPos += num->second * a_Scale;
				}
			}

			glBindTexture(GL_TEXTURE_2D, m_Pages[letter.page].m_TexId);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			glDrawArrays(GL_TRIANGLES, 0, 6);
		}
		if (a_Letters[index] == '\n') {
			yPos += m_Common.lineHeight * a_Scale;
			xPos = a_X;
		}

		index++;
	}

	//end
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE, 0);
}


int Font::getsSubString(const std::string* const a_Input, std::string* a_Output, int a_Start, char a_Prefix, char a_Suffix) {
	int start = a_Input->find_first_of(a_Prefix, a_Start) + 1;
	int end = a_Input->find_first_of(a_Suffix, start);
	a_Output->assign(a_Input->substr(start, end - start));

	return end;
}