/**--------------------------------------------------------------------------**\
					===========================
					 foreach efficient looping
					===========================
Description:
	Provides efficient looping through sparse data sets, such as connected
	players.  Significantly improved from the original version to be a generic
	loop system, rather then purely a player loop system.  When used for
	players this has constant time O(n) for number of connected players (n),
	unlike standard player loops which are O(MAX_PLAYERS), regardless of the
	actual number of connected players.  Even when n is MAX_PLAYERS this is
	still faster.
	
	For extensive documentation on writing and using iterators, see this topic:
	
		http://forum.sa-mp.com/showthread.php?t=481877
	
Legal:
	Version: MPL 1.1
	
	The contents of this file are subject to the Mozilla Public License Version 
	1.1 (the "License"); you may not use this file except in compliance with 
	the License. You may obtain a copy of the License at 
	[url]http://www.mozilla.org/MPL/[/url]
	
	Software distributed under the License is distributed on an "AS IS" basis,
	WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
	for the specific language governing rights and limitations under the
	License.
	
	The Original Code is the YSI foreach include.
	
	The Initial Developer of the Original Code is Alex "Y_Less" Cole.
	Portions created by the Initial Developer are Copyright (C) 2011
	the Initial Developer. All Rights Reserved.
	
	Contributors:
		ZeeX, koolk, JoeBullet/Google63, g_aSlice/Slice
	
	Thanks:
		JoeBullet/Google63 - Handy arbitrary ASM jump code using SCTRL.
		ZeeX - Very productive conversations.
		koolk - IsPlayerinAreaEx code.
		TheAlpha - Danish translation.
		breadfish - German translation.
		Fireburn - Dutch translation.
		yom - French translation.
		50p - Polish translation.
		Zamaroht - Spanish translation.
		Dracoblue, sintax, mabako, Xtreme, other coders - Producing other modes
			for me to strive to better.
		Pixels^ - Running XScripters where the idea was born.
		Matite - Pestering me to release it and using it.
	
	Very special thanks to:
		Thiadmer - PAWN, whose limits continue to amaze me!
		Kye/Kalcor - SA:MP.
		SA:MP Team past, present and future - SA:MP.
	
Version:
	0.4
Changelog:
	29/03/15:
		More testing.
		Repaired special iterators.
	28/03/15:
		Breaking change: "Iter_Add" returns value added, not true/false.
		Breaking change: Special iterators take "cellmin", not "-1".
		Wrote many tests.
		Split in to multiple files.
		Added multi-iterators.
		Officially deprecated "foreach (Player, i)".
	26/03/15:
		Re-added reverse iterators.
		Added support for extra spaces in "foreach".
	26/12/13:
		Added sections.
	17/10/12:
		Fixed a bug that was here but not in "foreach.inc".
	04/10/12:
		Added a tiny tweak to detect tag-returning iterator functions.
		Added Iter_InternalSize.
	13/01/12:
		Fixed the count thanks to AndreT.
	05/01/12:
		Fixed multi-dimensional iterators.
		Fixed "FOREACH_NO_BOTS".
		Made "Iterator:" support multi-dimensional arrays.
	24/12/11:
		Added _YSI_SPECIAL_DEBUG support.
		Added fix for function iterators.
		Ported back to YSI.
		Changed to use internal YSI "__" natives.
		Fixed calls order by using ALS.
	31/10/11:
		Changed the underlying loop code to be slightly faster.
		Added support for Iter_SafeRemove, prompting refactoring.
	17/09/11:
		Fixed arrays under the new syntax.
	28/04/11:
		Moved iterator identifiers to end of variables.
		Rewrote "foreach" to accept two syntaxes for "foreach (new i : Iter)".
	16/08/10:
		Removed all the "2" versions of the functions.
	14/08/10:
		Added Iter_Clear to reset an array.
	06/08/10:
		Added special array declaration format.
	18/12/09:
		Added Iter_Func2 functions for multi-dimensional iterators.
		Renamed foreact et al as keywords in the documentation.
		Changed licensing from GPL to MPL.
	02/09/09:
		Fixed (again) for 0.3.
		Added free slot finding.
	21/08/09:
		Updated to include random functions.
		Made entirely stand alone.
		Ported to 0.3 (separate version).
		Added automatic callback hook code.
		Removed debug information from stand alone version.
	06/01/08:
		Added debug information.
	09/10/07:
		Moved to system.
	16/09/07:
		Added list sorting.
		Made this part of Y SeRver Includes, not Y Sever Includes.
		Made list sorting optional.
		Fixed version number.
	08/09/07:
		First version.
Functions:
	Public:
		OnPlayerDisconnect - Called when a player leaves to remove them.
		OnPlayerConnect - Called when a player connects to add them.
	Core:
		-
	Stock:
		Iter_ShowArray - Displays the contents of the array.
		Iter_AddInternal - Add a value to an iterator.
		Iter_RemoveInternal - Remove a value from an iterator.
		Iter_RandomInternal - Get a random item from an iterator.
		Iter_FreeInternal - Gets the first free slot in the iterator.
		Iter_InitInternal - Initialises a multi-dimensional iterator.
	Static:
		-
	Inline:
		Iter_Create - Create a new iterator value set.
		Iter_Add - Wraps Iter_AddInternal.
		Iter_Remove - Wraps Iter_RemoveInternal.
		Iter_Random - Wraps Iter_RandomInternal.
		Iter_Count - Gets the number of items in an iterator.
		Iter_Debug - Wraps around Iter_ShowArray.
		Iter_Free - Wraps around Iter_FreeInternal.
		Iter_Create2 - Create a new iterator array value set.
		Iter_Add2 - Wraps Iter_AddInternal for arrays.
		Iter_Remove2 - Wraps Iter_RemoveInternal for arrays.
		Iter_Random2 - Wraps Iter_RandomInternal for arrays.
		Iter_Count2 - Gets the number of items in an iterator array.
		Iter_Debug2 - Wraps around Iter_ShowArray for arrays.
		Iter_Free2 - Wraps around Iter_FreeInternal for arrays.
	API:
		-
Callbacks:
	-
Hooks:
	Iter_OnPlayerConnect - Hook for the OnPlayerConnect callback.
	Iter_OnPlayerDisconnect - Hook for the OnPlayerDisconnect callback.
	Iter_OnGameModeInit - Only exists to make the code compile correctly...
Definitions:
	-
Enums:
	-
Macros:
	-
Keywords:
	foreach - Command to loop an iterator.
	foreachex - Like foreach but without a new variable.
	foreach2 - Command to loop through an iterator array.
	foreachex - Like foreach2 but without a new variable.
Tags:
	Iterator - Declare an iterator.
Variables:
	Global:
		-
	Static:
		YSI_g_OPC - Records wether Iter_OnPlayerConnect exists for speed.
		YSI_g_OPDC - Records wether Iter_OnPlayerDisconnect exists for speed.
Commands:
	-
Compile options:
	YSI_ITTER_NO_SORT - Removed.
	FOREACH_NO_BOTS - Remove the bot iterators for smaller code.
	FOREACH_NO_PLAYERS - Remove all default code for player itteration.
Operators:
	-
Iterators:
	Player - List of all players connected.
	Bot - List of all bots (npcs) connected.
	NPC - Alias of Bot.
	Character - All players and bots.
\**--------------------------------------------------------------------------**/

/*

    88      a8P                                                                           88            
    88    ,88'                                                                            88            
    88  ,88"                                                                              88            
    88,d88'      ,adPPYba, 8b       d8 8b      db      d8  ,adPPYba,  8b,dPPYba,  ,adPPYb,88 ,adPPYba,  
    8888"88,    a8P_____88 `8b     d8' `8b    d88b    d8' a8"     "8a 88P'   "Y8 a8"    `Y88 I8[    ""  
    88P   Y8b   8PP"""""""  `8b   d8'   `8b  d8'`8b  d8'  8b       d8 88         8b       88  `"Y8ba,   
    88     "88, "8b,   ,aa   `8b,d8'     `8bd8'  `8bd8'   "8a,   ,a8" 88         "8a,   ,d88 aa    ]8I  
    88       Y8b `"Ybbd8"'     Y88'        YP      YP      `"YbbdP"'  88          `"8bbdP"Y8 `"YbbdP"'  
                               d8'                                                                      
                              d8'                                                                       

*/

/**--------------------------------------------------------------------------**\
Array:
	Iterator
</returns>
<remarks>
	Creates a new iterator start/array pair.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iterator:%1<%2> Iterator@%1[_:F@c:F@d:((%2)+1)]={(-(%2)*((%2)-1)),(-(%2)*((%2)-2)),...}F@a$,Iter_Single@%1 F@a$F@a$

/**--------------------------------------------------------------------------**\
<summary>foreach</summary>
<param name="data">Data to itterate through.</param>
<param name="as">Variable to set value to.</param>
<returns>
	-
</returns>
<remarks>
	Not exactly the same as PHP foreach, just iterates through a list and
	returns the value of the current slot but uses that slot as the next index
	too.  Variables must be in the form @YSII_<gname>S for the start index and
	@YSII_<gname>A for the data array where <name> is what's entered in data.
</remarks>
\**--------------------------------------------------------------------------**/

#define foreach(%0) for(new Y_FOREACH_SECOND|||Y_FOREACH_THIRD|||%0|||)

/**--------------------------------------------------------------------------**\
<summary>iterfunc</summary>
<returns>
	-
</returns>
<remarks>
	Used to declare a special iterator function.
</remarks>
\**--------------------------------------------------------------------------**/

#define iterfunc%0(%1) F@y:%0(%1)

/**--------------------------------------------------------------------------**\
<summary>iterstart</summary>
<returns>
	-
</returns>
<remarks>
	Used to declare the default special iterator value.
</remarks>
\**--------------------------------------------------------------------------**/

/**--------------------------------------------------------------------------**\
<summary>Reverse</summary>
<returns>
	-
</returns>
<remarks>
	Run an iterator backwards.
</remarks>
\**--------------------------------------------------------------------------**/

#define iterstart@Reverse%9$);%9!=_:(%1=%9(_:%9,%0)); F@p:F@q:$%1,%0$

/*

    88b           d88            88                       db        88888888ba  88  
    888b         d888            ""                      d88b       88      "8b 88  
    88`8b       d8'88                                   d8'`8b      88      ,8P 88  
    88 `8b     d8' 88 ,adPPYYba, 88 8b,dPPYba,         d8'  `8b     88aaaaaa8P' 88  
    88  `8b   d8'  88 ""     `Y8 88 88P'   `"8a       d8YaaaaY8b    88""""""'   88  
    88   `8b d8'   88 ,adPPPPP88 88 88       88      d8""""""""8b   88          88  
    88    `888'    88 88,    ,88 88 88       88     d8'        `8b  88          88  
    88     `8'     88 `"8bbdP"Y8 88 88       88    d8'          `8b 88          88  

*/

/**--------------------------------------------------------------------------**\
<summary>Iter_Init</summary>
<param name="iter">Name of the iterator array to initialise.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_Init_Internal.  When "NESTED_ELLIPSIS" is set, this isn't
	needed because multi-dimensional iterators can be initialised with the new
	"{{0, 1, ...), ...}" feature.  In that case "I@ = 0" is called as a "void"
	function that does nothing but ends in a semi-colon ("I@" is used a lot in
	YSI as a "do nothing" enabler).

native Iter_Init(IteratorArray:Name[]<>);

</remarks>
\**--------------------------------------------------------------------------**/

#if defined NESTED_ELLIPSIS
	#define Iter_Init(%0) (I@=0)
#else
	#define Iter_Init(%0) Iter_Init_Internal(F@r(Iterator@%0),F@r(Iterator@%0)[0],F@s(Iterator@%0),F@s(Iterator@%0[]),F@r(Iter_Init@%0))
#endif

/**--------------------------------------------------------------------------**\
<summary>Iter_Add</summary>
<param name="iter">Name of the iterator to add the data to.</param>
<param name="value">Value to add to the iterator.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_AddInternal.

native Iter_Add(Iterator:Name<>, value);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Add _ITER<Add>
#define Iter_Add_InternalA(%0,%1,%9)    Iter_Add_InternalC(%0,_:%1,F@s(%1)-1,_:F@t:((%1[0]-%1[0])+%9))
#define Iter_Add_InternalB(%0,%2,%1,%9) Iter_Add_InternalD(%0[%2],_:%1,F@s(%1)-1-(%2),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))

/**--------------------------------------------------------------------------**\
<summary>Iter_Remove</summary>
<param name="iter">Name of the iterator to remove data from.</param>
<param name="value">Data to remove.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_RemoveInternal.

native Iter_Remove(Iterator:Name<>, value);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Remove _ITER<Remove>
#define Iter_Remove_InternalA(%0,%1,%9)    Iter_Remove_InternalC(%0,_:%1,F@s(%1)-1,_:F@t:((%1[0]-%1[0])+%9))
#define Iter_Remove_InternalB(%0,%2,%1,%9) Iter_Remove_InternalD(%0[%2],_:%1,F@s(%1)-1-(%2),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))

/**--------------------------------------------------------------------------**\
<summary>Iter_Free</summary>
<param name="iter">Name of the iterator to get the first free slot in.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_Free_Internal.  Returns a slot NOT in the current
	iterator.

native Iter_Free(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Free _ITER<Free>
#define Iter_Free_InternalA(%0,%1)    Iter_Free_Internal(_:%1,F@s(%1)-F@s(%0))
#define Iter_Free_InternalB(%0,%2,%1) Iter_Free_Internal(_:%1,F@s(%1)-F@s(%0))

/**--------------------------------------------------------------------------**\
<summary>Iter_FreeMulti</summary>
<param name="iter">Name of the multi-iterator to get the first free slot in.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_FreeMulti_Internal.  Returns a slot NOT in the current
	multi-iterator.

native Iter_FreeMulti(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_FreeMulti _ITER<FreeMulti>
#define Iter_FreeMulti_InternalA(%0,%1)    Iter_FreeMulti_Internal(_:%1,F@s(%1),F@s(%1)-F@s(%0))
#define Iter_FreeMulti_InternalB(%0,%2,%1) Iter_FreeMulti_Internal(_:%1,F@s(%1),F@s(%1)-F@s(%0))

/**--------------------------------------------------------------------------**\
<summary>Iter_Contains</summary>
<param name="iter">Name of the iterator to check membership of.</param>
<param name="value">Value to check.</param>
<returns>
	-
</returns>
<remarks>
	Checks if the given value is in the given iterator.

native Iter_Contains(Iterator:Name<>, value);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Contains(%0) (bool:_ITER<Contains>(%0))
#define Iter_Contains_InternalA(%0,%1,%9)     Iter_Contains_InternalC(_:%1,F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))
#define Iter_Contains_InternalB(%0,%2,%1,%9)  Iter_Contains_InternalD(%0[%2],_:%1,F@s(%1)-F@s(%0),-%2+F@s(%1)-1,_:F@t:((%1[0]-%1[0])+%9))
#define Iter_Contains_InternalD(%0,%1,%2,-+%8,%3) Iter_Contains_InternalC(%1,%2,%3)

/**--------------------------------------------------------------------------**\
<summary>Iter_GetMulti</summary>
<param name="iter">Name of the iterator to check membership of.</param>
<param name="value">Value to check.</param>
<returns>
	Index in which the value is contained in the multi-iterator.
</returns>
<remarks>
	Checks if the given value is in the given iterator, and if it is return which index it is contained.

native Iter_GetMulti(Iterator:Name<>, value);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_GetMulti _ITER<GetMulti>
#define Iter_GetMulti_InternalA(%0,%1,%9)    Iter_GetMulti_Internal(_:%1,F@s(%1),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))
#define Iter_GetMulti_InternalB(%0,%2,%1,%9) Iter_GetMulti_Internal(_:%1,F@s(%1),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))

/**--------------------------------------------------------------------------**\
<summary>Iter_SafeRemove</summary>
<param name="iter">Name of the iterator to remove data from.</param>
<param name="value">Data to remove.</param>
<param name="next">Container for the pointer to the next element.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_SafeRemoveInternal.  Common use:
	
	Iter_SafeRemove(iter, i, i);

native Iter_SafeRemove(Iterator:Name<>, value, &next);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_SafeRemove _ITER<SafeRemove>
#define Iter_SafeRemove_InternalA(%0,%1,%9)    Iter_SafeRemove_InternalC(%0,_:%1,F@s(%1)-1,_:F@t:((%1[0]-%1[0])+%9))
#define Iter_SafeRemove_InternalB(%0,%2,%1,%9) Iter_SafeRemove_InternalD(%0[%2],_:%1,F@s(%1)-1-(%2),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))

/**--------------------------------------------------------------------------**\
<summary>Iter_RandomAdd</summary>
<param name="iter">Name of the iterator to add a random slot to.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_RandomAddInternal.

native Iter_RandomAdd(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_RandomAdd _ITER<RandomAdd>
#define Iter_RandomAdd_InternalA(%0,%1)    Iter_RandomAdd_InternalC(%0,_:%1,F@s(%1)-1)
#define Iter_RandomAdd_InternalB(%0,%2,%1) Iter_RandomAdd_InternalD(%0,_:%1,F@s(%1)-F@s(%0),F@s(%0),F@s(%1)-1-(%2),%2)

/**--------------------------------------------------------------------------**\
<summary>Iter_RandomRemove</summary>
<param name="iter">Name of the iterator to remove a random slot from.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_RandomRemoveInternal.

native Iter_RandomRemove(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_RandomRemove _ITER<RandomRemove>
#define Iter_RandomRemove_InternalA(%0,%1)    Iter_RandomRemove_InternalC(%0,_:%1,F@s(%1)-1)
#define Iter_RandomRemove_InternalB(%0,%2,%1) Iter_RandomRemove_InternalD(%0[%2],_:%1,F@s(%1)-F@s(%0),F@s(%1)-1-(%2))

/**--------------------------------------------------------------------------**\
<summary>Iter_RandomFree</summary>
<param name="iter">Name of the iterator to get a random unused slot for.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_RandomFree_Internal.

native Iter_RandomFree(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_RandomFree _ITER<RandomFree>
#define Iter_RandomFree_InternalA(%0,%1)    Iter_RandomFree_InternalC(%0,_:%1,F@s(%1)-1)
#define Iter_RandomFree_InternalB(%0,%2,%1) Iter_RandomFree_InternalD(%0,_:%1,F@s(%1)-F@s(%0),F@s(%0))

/**--------------------------------------------------------------------------**\
<summary>Iter_Random</summary>
<param name="iter">Name of the iterator to get a random slot from.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_RandomInternal.

native Iter_Random(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Random _ITER<Random>
#define Iter_Random_InternalA(%0,%1)    Iter_Random_Internal(%0,_:%1,F@s(%1)-1)
#define Iter_Random_InternalB(%0,%2,%1) Iter_Random_Internal(%0[%2],_:%1,F@s(%1)-1-(%2))

/**--------------------------------------------------------------------------**\
<summary>Iter_Count</summary>
<param name="iter">Name of the iterator to get a random slot from.</param>
<returns>
	-
</returns>
<remarks>
	Returns the number of items in this iterator.

native Iter_Count(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Count _ITER<Count>
#define Iter_Count_InternalA(%0,%1)    (%0)
#define Iter_Count_InternalB(%0,%2,%1) (%0[%2])

/**--------------------------------------------------------------------------**\
<summary>Iter_Clear</summary>
<param name="iter">Name of the iterator to empty.</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_Clear_Internal.
	
	Although it doesn't fit my normal strict spacing, the end of "B" is correct,
	namely: "_:F@s(%0),%2)".  This uses the "_:%0,)" macro to consume
	a trailing comma when nothing is given in "%2", so I can't have a leading
	space sadly.
	
	"- 2" in place of the normal "- 1" is CORRECT!

native Iter_Clear(IteratorArray:Name[]<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Clear _ITER<Clear>
#define Iter_Clear_InternalA(%0,%1)           Iter_Clear_InternalC(_:%1,F@s(%1),F@s(%0),F@s(%1)-2,%0)
#define Iter_Clear_InternalB(%0,%2,%1)        Iter_Clear_InternalD(_:%1,F@s(%1),F@s(%0),F@s(%1)-F@s(%0),%0,%2)
#define Iter_Clear_InternalD(%0,%1,%2,%3,%4,) Iter_Clear_InternalC(%0,%1,%2,%3-1,%4)

/**--------------------------------------------------------------------------**\
<summary>Iter_Alloc</summary>
<param name="iter">Name of the iterator to get the first free slot in.</param>
<returns>
	-
</returns>
<remarks>
	Finds an empty slot in an iterator, adds that slot to the iterator, and
	returns the now added slot.

native Iter_Alloc(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Alloc _ITER<Alloc>
#define Iter_Alloc_InternalA(%0,%1)    Iter_Alloc_InternalC(%0,_:%1,F@s(%1)-1)
#define Iter_Alloc_InternalB(%0,%2,%1) Iter_Alloc_InternalD(%0[%2],_:%1,F@s(%1)-1-(%2),F@s(%1)-F@s(%0))

/*

    88888888888                                                     db        88888888ba  88  
    88                        ,d                                   d88b       88      "8b 88  
    88                        88                                  d8'`8b      88      ,8P 88  
    88aaaaa     8b,     ,d8 MM88MMM 8b,dPPYba, ,adPPYYba,        d8'  `8b     88aaaaaa8P' 88  
    88"""""      `Y8, ,8P'    88    88P'   "Y8 ""     `Y8       d8YaaaaY8b    88""""""'   88  
    88             )888(      88    88         ,adPPPPP88      d8""""""""8b   88          88  
    88           ,d8" "8b,    88,   88         88,    ,88     d8'        `8b  88          88  
    88888888888 8P'     `Y8   "Y888 88         `"8bbdP"Y8    d8'          `8b 88          88  

*/

/**--------------------------------------------------------------------------**\
<summary>Iter_FastClear</summary>
<param name="iter">Name of the iterator to empty.</param>
<returns>
	-
</returns>
<remarks>
	Uses a static array copy to blank the iterator instead of a loop.
	
	BROKEN!

native Iter_FastClear(IteratorArray:Name[]<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_FastClear _ITER<FastClear>
#define Iter_FastClear_InternalA(%0,%1);    {static YSII_Xg@Clear[F@s(%1)]={0,1,...};%1=YSII_Xg@Clear;%0=0;}
#define Iter_FastClear_InternalB(%0,%2,%1); {static YSII_Xg@Clear[F@s(%1)]={0,1,...},YSII_Yg@Clear[F@s(%0)]={0,0,...};%1=YSII_Xg@Clear;%0=YSII_Yg@Clear;}

/**--------------------------------------------------------------------------**\
<summary>Iter_Begin</summary>
<param name="iter">Name of the iterator to get the start of.</param>
<returns>
	-
</returns>
<remarks>
	Gets a point BEFORE the start of the iterator (the theoretical beginning).
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Begin _ITER<Begin>
#define Iter_Begin_InternalA(%0,%1)    (F@s(%1)-F@s(%0))
#define Iter_Begin_InternalB(%0,%2,%1) (F@s(%1)-1-(%2))

/**--------------------------------------------------------------------------**\
<summary>Iter_End</summary>
<param name="iter">Name of the iterator to get the end of.</param>
<returns>
	-
</returns>
<remarks>
	Gets a point AFTER the end of the iterator (think "MAX_PLAYERS").
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_End _ITER<End>
#define Iter_End_InternalA(%0,%1)    (F@s(%1)-F@s(%0))
#define Iter_End_InternalB(%0,%2,%1) (F@s(%1)-1-(%2))

/**--------------------------------------------------------------------------**\
<summary>Iter_First</summary>
<param name="iter">Name of the iterator to get the first valid element in.</param>
<returns>
	-
</returns>
<remarks>
	Gets the first element in an iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_First _ITER<First>
#define Iter_First_InternalA(%0,%1)    (%1[(F@s(%1)- F@s(%0))])
#define Iter_First_InternalB(%0,%2,%1) (%1[(F@s(%1)-1-(%2))])

/**--------------------------------------------------------------------------**\
<summary>Iter_Last</summary>
<param name="iter">Name of the iterator to</param>
<returns>
	-
</returns>
<remarks>
	Gets the last element in an iterator.  Works by getting the previous item
	from the one BEFORE the first element (i.e. the one before the sentinel).
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Last _ITER<Last>
#define Iter_Last_InternalA(%0,%1)    ((%1[Iter_End_InternalA(%0,%1)-1])-1)
#define Iter_Last_InternalB(%0,%2,%1) (Iter_Prev_InternalB(%0,%2,%1,Iter_End_InternalB(%0,%2,%1)))

/**--------------------------------------------------------------------------**\
<summary>Iter_Next</summary>
<param name="iter">Name of the iterator to get the next element in.</param>
<param name="cur">The current element.</param>
<returns>
	-
</returns>
<remarks>
	Gets the element in an iterator after the current one.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Next _ITER<Next>
#define Iter_Next_InternalA(%0,%1,%9)    (%1[_:F@t:((%1[0]-%1[0])+%9)])
#define Iter_Next_InternalB(%0,%2,%1,%9) (%1[_:F@t:((%1[0]-%1[0])+%9)])

/**--------------------------------------------------------------------------**\
<summary>Iter_Prev</summary>
<param name="iter">Name of the iterator to get the previous element in.</param>
<param name="cur">The current element.</param>
<returns>
	-
</returns>
<remarks>
	Gets the element in an iterator before the current one.  Slow.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Prev _ITER<Prev>
#define Iter_Prev_InternalA(%0,%1,%9)    (((%1[(_:((%1[0]-%1[0])+%9)-1)%F@s(%1)])-1)%F@s(%1))
#define Iter_Prev_InternalB(%0,%2,%1,%9) Iter_Prev_Internal(%1,F@s(%1)-F@s(%0),F@s(%1),_:F@t:((%1[0]-%1[0])+%9))

/**--------------------------------------------------------------------------**\
<summary>Iter_TrueArray</summary>
<param name="iter">Name of the iterator to get the true array of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the internal array of an iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_TrueArray(%1) F@r(Iterator@%1)

/**--------------------------------------------------------------------------**\
<summary>Iter_TrueCount</summary>
<param name="iter">Name of the iterator to get the true count of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the internal count of an iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_TrueCount(%1) F@r(Iter_Single@%1)

/**--------------------------------------------------------------------------**\
<summary>Iter_TrueMulti</summary>
<param name="iter">Multi iterator to get the true count of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the internal count of a multi-iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_TrueMulti(%1) F@r(Iter_Multi@%1)

/**--------------------------------------------------------------------------**\
<summary>Iter_TrueSize</summary>
<param name="iter">Name of the iterator to get the true size of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the internal size of an iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_TrueSize _ITER<TrueSize>
#define Iter_TrueSize_InternalA(%0,%1)    (F@s(%1))
#define Iter_TrueSize_InternalB(%0,%2,%1) (F@s(%1))

/**--------------------------------------------------------------------------**\
<summary>Iter_Starts</summary>
<param name="iter">Name of the iterator to get the true starts of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the number of starts in a multi-iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Starts _ITER<Starts>
#define Iter_Starts_InternalA(%0,%1)    (F@s(%0))
#define Iter_Starts_InternalB(%0,%2,%1) (F@s(%0))

/**--------------------------------------------------------------------------**\
<summary>Iter_Size</summary>
<param name="iter">Name of the iterator to get the size of.</param>
<returns>
	-
</returns>
<remarks>
	Accesses the size of an iterator.
</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Size _ITER<Size>
#define Iter_Size_InternalA(%0,%1)    (F@s(%1)-F@s(%0))
#define Iter_Size_InternalB(%0,%2,%1) (F@s(%1)-F@s(%0))

/**--------------------------------------------------------------------------**\
<summary>Iter_Index</summary>
<param name="iter">Name of the iterator to get a slot in by index.</param>
<param name="index">Index.</param>
<param name="wrap">Keep going around until a value is found?</param>
<returns>
	-
</returns>
<remarks>
	Wrapper for Iter_Index_Internal.  Returns the Nth value in the iterator
	(requires looping due to the way iterators are stored and optimised for
	loops not direct access).

native Iter_Index(Iterator:Name<>);

</remarks>
\**--------------------------------------------------------------------------**/

#define Iter_Index _ITER<Index>
#define Iter_Index_InternalA(%0,%1,%9)    Iter_Index_Internal(%0,%1,F@s(%1)-1,F@s(%1)-1,_:F@t:((%1[0]-%1[0])+%9))
#define Iter_Index_InternalB(%0,%2,%1,%9) Iter_Index_Internal(%0[%2],%1,F@s(%1)-1-(%2),F@s(%1)-F@s(%0),_:F@t:((%1[0]-%1[0])+%9))

/*

    88b           d88                                                         
    888b         d888                                                         
    88`8b       d8'88                                                         
    88 `8b     d8' 88 ,adPPYYba,  ,adPPYba, 8b,dPPYba,  ,adPPYba,  ,adPPYba,  
    88  `8b   d8'  88 ""     `Y8 a8"     "" 88P'   "Y8 a8"     "8a I8[    ""  
    88   `8b d8'   88 ,adPPPPP88 8b         88         8b       d8  `"Y8ba,   
    88    `888'    88 88,    ,88 "8a,   ,aa 88         "8a,   ,a8" aa    ]8I  
    88     `8'     88 `"8bbdP"Y8  `"Ybbd8"' 88          `"YbbdP"'  `"YbbdP"'  

*/

// Remove trailing spaces.  This looks really unsafe because of the "%0\32;"
// allowing anything to come before the space, but it would have to be
// "anything" not text immediately following a "YSII_X@" prefix.
#define Iterator@%0\32;%1$ Iterator@%0%1$
#define Iter_Func@%0\32;%1$ Iter_Func@%0%1$
#define iterstart@%0\32;%1$ iterstart@%0%1$
#define Iter_Single@%0\32;%1$ Iter_Single@%0%1$
#define Iter_Multi@%0\32;%1$ Iter_Multi@%0%1$
#define Iter_Init@%0\32;%1$ Iter_Init@%0%1$

// Allow "iterfunc stock", "stock iterfunc", and other varieties.
#define Iter_Func@stock%0(%2)%1$ stock F@y:%0(%2)
#define Iter_Func@static%0(%2)%1$ static F@y:%0(%2)
#define Iter_Func@foreign%0(%2)%1$ foreign F@y:%0(%2)
#define Iter_Func@global%0(%2)%1$ global F@y:%0(%2)
#define Iter_Func@public%0(%2)%1$ public F@y:%0(%2)
#define Iter_Func@forward%0(%2)%1$ forward F@y:%0(%2)

#define ITER_TAG_FUNC(%0)%1(%2) %0:Iter_Func@%1(%2)

// Many tag types that may come up as iterator function return types.
#define Iter_Func@_:            ITER_TAG_FUNC(_)
#define Iter_Func@bool:         ITER_TAG_FUNC(bool)
#define Iter_Func@PlayerText3D: ITER_TAG_FUNC(PlayerText3D)
#define Iter_Func@Text3D:       ITER_TAG_FUNC(Text3D)
#define Iter_Func@DB:           ITER_TAG_FUNC(DB)
#define Iter_Func@DBResult:     ITER_TAG_FUNC(DBResult)
#define Iter_Func@Language:     ITER_TAG_FUNC(Language)
#define Iter_Func@Bit:          ITER_TAG_FUNC(Bit)
#define Iter_Func@Text:         ITER_TAG_FUNC(Text)
#define Iter_Func@Menu:         ITER_TAG_FUNC(Menu)
#define Iter_Func@Style:        ITER_TAG_FUNC(Style)
#define Iter_Func@XML:          ITER_TAG_FUNC(XML)
#define Iter_Func@Bintree:      ITER_TAG_FUNC(Bintree)
#define Iter_Func@Group:        ITER_TAG_FUNC(Group)
#define Iter_Func@Timer:        ITER_TAG_FUNC(Timer)
#define Iter_Func@File:         ITER_TAG_FUNC(File)
#define Iter_Func@Float:        ITER_TAG_FUNC(Float)

#define ITER_TAG(%0)%1={%2,%3,...}%4: %0:Iterator@%1={%0:%2,%0:%3,...}F@a$,Iter_Single@

// Many tag types for declared iterators.
#define Iterator@_:            ITER_TAG(_)
#define Iterator@bool:         ITER_TAG(bool)
#define Iterator@PlayerText3D: ITER_TAG(PlayerText3D)
#define Iterator@Text3D:       ITER_TAG(Text3D)
#define Iterator@DB:           ITER_TAG(DB)
#define Iterator@DBResult:     ITER_TAG(DBResult)
#define Iterator@Language:     ITER_TAG(Language)
#define Iterator@Bit:          ITER_TAG(Bit)
#define Iterator@Text:         ITER_TAG(Text)
#define Iterator@Menu:         ITER_TAG(Menu)
#define Iterator@Style:        ITER_TAG(Style)
#define Iterator@XML:          ITER_TAG(XML)
#define Iterator@Bintree:      ITER_TAG(Bintree)
#define Iterator@Group:        ITER_TAG(Group)
#define Iterator@Timer:        ITER_TAG(Timer)
#define Iterator@File:         ITER_TAG(File)
#define Iterator@Float:        ITER_TAG(Float)

// A nice "match" symbol that we can scan for, then remove after it is used.
#define F@a$
#define F@b|||

// Detect array declarations: "Iterator:X[20]<4>", "Iterator:X<10, 4>", and the
// frankly silly "Iterator:X[20]<10, 4>".
#define F@c:F@d:((%0,%1)+1)]%2$,Iter_Single@%9$%7$ F@d:((%0)+(%1))]={0,1,...}F@a$,Iter_Multi@%9$[%0]%7$
#if defined NESTED_ELLIPSIS
	#define F@d:%0]%2$,Iter_%8@%9[%3$%7$ %0]={{0,1,...},...},Iter_%8@%9[%3$%7$
#else
	#define F@d:%0]%2$,Iter_%8@%9[%3$%7$ %0],Iter_%8@%9[%3$%7$,F@g(Iter_Init@%9,)=F@s(Iter_%8@%9[%3$)
#endif

// Special "sizeof" that strips subscripts.  "|||" prevents "sizeof" recursion.
#define F@e:%0|||(%1[%2]%3|||%4)) F@e:%0|||(%1%3|||%4[]))
#define F@f:%0|||(F@g(%1,%5)%3|||) %0|||(%1 %3|||)
#define F@s(%0) (_:F@f:F@e:sizeof F@b|||(%0 F@a$F@b|||))

// Reify macros.
#define F@r(%0) %0 F@a$
#define F@g(%0,%8) %0 F@a$
#define F@h:%0) %0 F@a$)

// Sort out tagged parameters plus extra parameters.
#define F@t:(%0,%1) (%0),%1

// y_iterate parser.  Takes an array input, and splits up all the components.
#define _ITER<%5>(%1) (_:F@i:F@j:$Iter_%5_Internal(%1))

// Separate "<>"s.  Parameters to the resulting macro/function:
//  
//   %0 - Count.
//   %1 - Multi iterator position.
//   %2 - Array.
//  ... - All other parameters.
//  
#define F@j:%7$%5(%0)       %5A(F@g(Iter_Single@%0,),F@h:Iterator@%0)
#define F@i:%7$%5(%0<%2>%1) %5B(F@h:Iter_Multi@%0,%2,F@h:Iterator@%0%1)

#define _Y_ITER_DO_FOREACH(%1,%0) (_:F@n:F@l:F@m:F@a$%1,%0$

// Multi-iterator.
#define F@n:%9$%1,%0<%2>$ F@s(Iterator@%0)-1-(%2));_:(%1=F@h:Iterator@%0[_:%1])<(F@s(Iterator@%0)-F@s(Iter_Multi@%0));

// Special iterator.
#define F@l:%9$%1,%0(%2)%8$ F@r(iterstart@%0));_:(F@r(iterstart@%0))!=_:(%1=F@h:Iter_Func@%0(_:%1,%2));

// Normal iterator.
#define F@m:%9$%1,%0$ F@s(Iterator@%0)-1);_:(%1=F@h:Iterator@%0[_:%1])!=(F@s(Iterator@%0)-1);

// Convert from a normal iterator to a special iterator with parameters.
#define F@o)-2)+%8$%1,%0[%2]()$ F@o)-2)+%8$%1,%0(%2)$

// Reverse multi-iterator.
#define F@p:%9$%1,%0<%2>$ F@s(Iterator@%0)-1-(%2));_:(%1=Iter_Prev_InternalB(Iter_Multi@%0,,Iterator@%0,%1))<(F@s(Iterator@%0)-F@s(Iter_Multi@%0));

// Reverse normal iterator.
#define F@q:%9$%1,%0$ F@s(Iterator@%0)-1);_:(%1=Iter_Prev_InternalA(,Iterator@%0,%1))!=(F@s(Iterator@%0)-1);

// Special iterator function declaration.
#define F@y:%0(%1) Iter_Func@%0(%1)F@a$

// Local state for iterator functions that need more than one variable.
#define iterstate(%5,%6)%9);%9!=_:(%1=%2( %5),itrst:Iter_State@%1=itrst:(%6);_:(%5)!=_:(%1=%2(_:Iter_State@%1,

// Make the internal state an array if there is more than one value.
#define itrst:%1=itrst:(%6,%7) %1[]={%6,%7}

// Consume spaces in the iterator state variables.
#define Iter_State@%0\32;%1) Iter_State@%0%1)

/**--------------------------------------------------------------------------**\
	The workings of these macros are very extensively documented at:
	
		http://forum.sa-mp.com/showpost.php?p=2823668
	
\**--------------------------------------------------------------------------**/

// This allows us to use "new" multiple times - stripping off ONLY whole words.
#define new%0|||%3|||%1:%2||| %3|||%0|||%1|||%2|||

// This one is called if the new syntax is required, but the state of "new" is
// as-yet unknown.  This attempts to call "%1" as a macro, if it starts with
// "new" as a whole word then it will (and will also helpfully strip off the
// "new" keyword for us).
#define Y_FOREACH_THIRD|||%9|||%1|||%2||| %1=Y_FOREACH_FIFTH|||Y_FOREACH_FOURTH|||%1:%2|||

// This is called if the "new" macro is called for a second time.
#define Y_FOREACH_FOURTH|||%1=Y_FOREACH_FIFTH|||%9|||%2||| new Y_FOREACH_SIXTH;%1|||Y_FOREACH_SEVENTH|||%2|||

// This is called when there are tags on the "new" declaration (%9 = "new ").
#define Y_FOREACH_SEVENTH|||%9Y_FOREACH_SIXTH;%0|||%1|||%2||| new %0:%1=%0:_Y_ITER_DO_FOREACH(%1,%2)

// This is called when there aren't.
#define Y_FOREACH_SIXTH;%1|||Y_FOREACH_SEVENTH|||%2||| %1=_Y_ITER_DO_FOREACH(%1,%2)

// This is called if "%1" didn't have "new" at the start.
#define Y_FOREACH_FIFTH|||Y_FOREACH_FOURTH|||%1:%2||| _Y_ITER_DO_FOREACH(%1,%2)

// This is the old version, but DON'T add "new" because that already exists from
// the failed "new" macro call above.
#define Y_FOREACH_SECOND|||Y_FOREACH_THIRD|||%2,%1||| using_deprecated_foreach_syntax,%1=_Y_ITER_DO_FOREACH(%1,%2)++using_deprecated_foreach_syntax

stock const
	// This variable is re-declared when you do "foreach (Player, i)" or similar
	// so that a warning is generated.  The warning will read:
	//   
	//   local variable "using_deprecated_foreach_syntax" shadows a variable at a preceding level
	//   
	// This is the best I could do to warn about the old syntax.  That code
	// should now be "foreach (new i : Player)".  It may become an error later.
	bool:using_deprecated_foreach_syntax = false,
	F@o[2];

