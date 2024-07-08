#include <Arduino.h>
#include <SD.h>		// this library has to be imported into Platformio IDE from here: https://platformio.org/lib/show/868/SD

#define MAX_FILENAME_LENGTH 11	//8.3 filename format
#define FILENAME_LENGTH 8

class CSDFilesManager
{
	public:
		// Constructors
		CSDFilesManager(uint8_t csPin) : m_Card()
		{
			// For UNO/NANO boards, SD library assumes using MOSI pin 11, MISO pin 12, CLK pin 13 as they are intended to be used for SPI protocol, and leaves CS configurable by the user
			m_bIsInitialized = false;
			m_bIsLastOperationOk = false;
			m_iCsPin = csPin;
		};

		// Public methods
		void Begin();
		String ReadFile();				//The xxxFile() methods use the path set through SetFile() method
		// If file exists, it appends. If bOverwrite is true, it will create file again regardless file exists.
		// NOTE: readed and writed filenames can't exceed 8.3 (8 characters name + 3 characters extension) format, if not it will fail!
		void WriteFile(String content, bool bOverwrite);
		void RemoveFile();
		void CreateDir(String sFolder);	//creates a folder and subfolder if path is indicating so, like 'mkdir -p', so it's not creating a file without extension instead of folder
		void RemoveDir(String sFolder);	//removes folder and its files recursively, like 'rm -rf'
		String ListFiles(String sFolder);	//use to list files from a directory, doesn't go deeper in the subfolder structure
		
		//Data accessor
		bool IsLastOperationOk()
		{
			return m_bIsLastOperationOk;
		};

		String FullPath()
		{
			return m_sFullPath;
		};

		void SetFile(String folder, String fileName)
		{
			if (folder.endsWith("/"))
			{
				SetFile(folder + fileName);
			}
			else
			{
				SetFile(folder + "/" + fileName);
			}
		};

		void SetFile(String fullPath)
		{
			if (fullPath.indexOf('/') > -1 &&
				fullPath[0] == '/')
				m_sFullPath = fullPath.substring(1);	//if path contains folder, avoid start with '/'. If it's a file in the root folder, don't use '/' in the path like '/file.xxx', use 'file.xxx' instead
			else
				m_sFullPath = fullPath;
		};
	private:
		// Fields
		SDClass m_Card;
		File m_File;
		uint8_t m_iCsPin;
		bool m_bIsInitialized;
		bool m_bIsLastOperationOk;
		String m_sFullPath;		//absolute path to file

		// Private methods
		String ListDirectory(File dir, const String sFolder);
		void SetAdaptedPath();
};
