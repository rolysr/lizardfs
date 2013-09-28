#ifndef LIZARDFS_MFSCHUNKSERVER_CHUNK_FILENAME_PARSER_H_
#define LIZARDFS_MFSCHUNKSERVER_CHUNK_FILENAME_PARSER_H_

#include <string>

#include "mfscommon/chunk_type.h"
#include "mfscommon/parser.h"

class ChunkFilenameParser : public Parser {
public:
	enum Status {
		OK,
		ERROR_INVALID_FILENAME
	};

	ChunkFilenameParser(const std::string& filename);
	Status parse();
	ChunkType chunkType() const;
	uint32_t chunkVersion() const;
	uint64_t chunkId() const;
	ChunkType::XorPart xorPart() const;
	ChunkType::XorLevel xorLevel() const;

private:
	static const size_t kChunkVersionStringSize = 8;
	static const size_t kChunkIdStringSize = 16;

	std::string chunkName_;
	ChunkType chunkType_;
	uint32_t chunkVersion_;
	uint64_t chunkId_;
	ChunkType::XorPart xorPart_;
	ChunkType::XorLevel xorLevel_;

	Status parseChunkType();
};

#endif // LIZARDFS_MFSCHUNKSERVER_CHUNK_FILENAME_PARSER_H_
