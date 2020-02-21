#include "CSDFilesManager.h"

#pragma region Public methods

void CSDFilesManager::Begin()
{
    if (!m_bIsInitialized)
    {
        m_bIsInitialized = m_Card.begin(m_iCsPin);
    }
    m_bIsLastOperationOk = m_bIsInitialized;
}

String CSDFilesManager::ReadFile()
{
    String sContent = "";

    if (m_bIsInitialized &&
        m_Card.exists(m_sFullPath))
    {
        m_File = m_Card.open(m_sFullPath);
        if (m_File)
        {
            sContent = m_File.readString();
            m_File.close();
            m_bIsLastOperationOk = true;
        }
        else
            m_bIsLastOperationOk = false;
    }

    return sContent;
}

void CSDFilesManager::WriteFile(String content, bool bOverwrite)
{
    if (m_bIsInitialized)
    {
        SetAdaptedPath();
        if (bOverwrite)
        {
            //force remove file as FILE_WRITE only creates file if not existing and appends if existing
            RemoveFile();
        }

        m_File = m_Card.open(m_sFullPath, FILE_WRITE);
        if (m_File)
        {
            m_File.print(content);
            m_File.close();
            m_bIsLastOperationOk = true;
        }
        else
            m_bIsLastOperationOk = false;
    }
}

void CSDFilesManager::RemoveFile()
{
    if (m_bIsInitialized &&
        m_Card.exists(m_sFullPath))
    {
       m_bIsLastOperationOk = m_Card.remove(m_sFullPath);
    }
}

void CSDFilesManager::CreateDir(String sFolder)
{
    if (m_bIsInitialized &&
        !m_Card.exists(sFolder) &&
        sFolder.length() > 0)
    {
        m_bIsLastOperationOk = m_Card.mkdir(sFolder);
    }
}

void CSDFilesManager::RemoveDir(String sFolder)
{
    if (m_bIsInitialized &&
        m_Card.exists(sFolder) &&
        sFolder.length() > 0)
    {
        m_bIsLastOperationOk = m_Card.rmdir(sFolder);
    }
}

String CSDFilesManager::ListFiles(String sFolder)
{
    if (m_bIsInitialized)
    {
        String sFiles = "";

        m_File = m_Card.open(sFolder);
        if (m_File)
        {
            sFiles = ListDirectory(m_File, sFolder);
            m_bIsLastOperationOk = true;
            return sFiles;
        }
        else
        {
            m_bIsLastOperationOk = false;
            return "";
        }
    }
}

#pragma endregion

// Private methods
String CSDFilesManager::ListDirectory(File dir, const String sFolder)
{
    String sFiles = "";
    File entry = dir.openNextFile();

    while (entry)
    {      
        if (entry.isDirectory())
        {
            ///listing from root '/' is not capable of going more that 1 levels of subdirectories (i.e: 'a.txt; level1/b.txt').
            ///From the first level, it can go deeper but only 2 levels (i.e: 'level1/a.txt; level1/level2/b.txt; level1/level2/level3/c.txt...'). Problems with the stack due to recursivity?
            //sFiles += ListDirectory(entry, String(sFolder + entry.name() + '/'));
        }
        else
        {
            // if file, post size as directories don't have it
            //sFiles += "Size: " + String(entry.size(), DEC) + "\r\n";
            sFiles += sFolder + String(entry.name()) + ';';
        }
        entry.close();
        entry = dir.openNextFile();
    }

    return sFiles;
}

void CSDFilesManager::SetAdaptedPath()
{
    String sFilename, sFolder;
    int iLastSlash = m_sFullPath.lastIndexOf('/');
    if (iLastSlash > -1)
    {
        iLastSlash++;
        sFolder = m_sFullPath.substring(0, iLastSlash); //include the slash
        sFilename = m_sFullPath.substring(iLastSlash, m_sFullPath.length());    //filename without slash and with the extension

        if (!m_Card.exists(sFolder))                    //create the folder from the path if doesn't exist. Method called only when writing file
        {
            CreateDir(sFolder);
        }
    }
    else
    {
        sFolder = "";
        sFilename = m_sFullPath;
    }   

    if (sFilename.length() > MAX_FILENAME_LENGTH)
    {
        //adapt to 8.3 format by truncating the filename keeping the rest of the path
        m_sFullPath = (sFolder + sFilename.substring(0, FILENAME_LENGTH) + m_sFullPath.substring(m_sFullPath.length() - 4));
    }
}