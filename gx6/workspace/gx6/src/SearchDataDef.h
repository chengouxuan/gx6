#ifndef GX6_SEARCH_DATA_DEF
#define GX6_SEARCH_DATA_DEF


namespace GX6SearchData {

	enum {
		ROW_MAX = 19,
		COL_MAX = 19
	};

	enum CellType {
		CELL_TYPE_BLACK,
		CELL_TYPE_WHITE,
		CELL_TYPE_EMPTY,
		CELL_TYPE_NOT_A_CELL
	};
	typedef CellType Board[ROW_MAX][COL_MAX];

	struct SearchData {
		CellType _board[ROW_MAX][COL_MAX];
		bool _isBlack;
		int _moves;
	};

	const int PARAM_SIZE_MAX = 1024;

	struct RequestData {
		enum Type {
			TYPE_EXIT,
			TYPE_SEARCH,
			TYPE_PARAM,
			TYPE_TERM_SEARCH,
			TYPE_BREAK_ALL_SEARCH
		} _type;
		union Data {
			SearchData _searchData;
			int _param[PARAM_SIZE_MAX];
		} _data;
	};

	struct MoveData {
		int _r1, _c1, _r2, _c2;
		MoveData() {}
		MoveData(int r1, int c1, int r2, int c2): _r1(r1), _c1(c1), _r2(r2), _c2(c2) {}
	};


}

#endif // GX6_SEARCH_DATA_DEF

