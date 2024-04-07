#pragma once

int intCompare(const void* a, const void* b, void* context);

int stringCompare(const void* a, const void* b, void* context);

//...

int compareByName(const void* a, const void* b, void* context);

int compareByAge(const void* a, const void* b, void* context);