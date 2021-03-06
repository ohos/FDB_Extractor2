#pragma once

#include "FDBPackage.h"

class FDBFile
{
    public:
        FDBFile(const FDBPackage::file_info& s_info, BYTE* data );
        virtual ~FDBFile();

		std::string FDBFile::GetTargetName(const char* filename, FDBPackage::e_export_format e=FDBPackage::EX_NONE);
        bool WriteToFile(const char*, FDBPackage::e_export_format e=FDBPackage::EX_NONE);
        virtual bool ExportFormatIsValid(FDBPackage::e_export_format e)    { return e==FDBPackage::EX_RAW; };
        virtual FDBPackage::e_export_format DefaultFormat()    { return FDBPackage::EX_RAW; };

        virtual bool WriteRAW(const char*);
        virtual bool WriteINI(const char* filename);
        virtual bool WriteLUA(const char* filename);
        virtual bool WriteCSV(const char* filename);
        virtual bool WriteSQLITE3(const char* filename, const char* table_name);

    protected:
        size_t  data_size;
        BYTE*   data;
};

