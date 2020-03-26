// Copyright (c) 2015-2019 The Khronos Group Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// 
// ---- Exceptions to the Apache 2.0 License: ----
// 
// As an exception, if you use this Software to generate code and portions of
// this Software are embedded into the generated code as a result, you may
// redistribute such product without providing attribution as would otherwise
// be required by Sections 4(a), 4(b) and 4(d) of the License.
// 
// In addition, if you combine or link code generated by this Software with
// software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
// ("`Combined Software`") and if a court of competent jurisdiction determines
// that the patent provision (Section 3), the indemnity provision (Section 9)
// or other Section of the License conflicts with the conditions of the
// applicable GPL or LGPL license, you may retroactively and prospectively
// choose to deem waived or otherwise exclude such Section(s) of the License,
// but only in their entirety and only with respect to the Combined Software.
//     

// This header is generated from the Khronos Vulkan XML API Registry.

#pragma once

#include "dispatch.hpp"

namespace VULKAN_HPP_NAMESPACE
{
  struct AllocationCallbacks;

  template <typename OwnerType, typename Dispatch>
  class ObjectDestroy
  {
    public:
      ObjectDestroy()
        : m_owner()
        , m_allocationCallbacks( nullptr )
        , m_dispatch( nullptr )
      {}

      ObjectDestroy( OwnerType owner, Optional<const AllocationCallbacks> allocationCallbacks = nullptr, Dispatch const &dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
        : m_owner( owner )
        , m_allocationCallbacks( allocationCallbacks )
        , m_dispatch( &dispatch )
      {}

      OwnerType getOwner() const VULKAN_HPP_NOEXCEPT { return m_owner; }
      Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        VULKAN_HPP_ASSERT( m_owner && m_dispatch );
        m_owner.destroy( t, m_allocationCallbacks, *m_dispatch );
      }

    private:
      OwnerType m_owner;
      Optional<const AllocationCallbacks> m_allocationCallbacks;
      Dispatch const* m_dispatch;
  };

  class NoParent;

  template <typename Dispatch>
  class ObjectDestroy<NoParent,Dispatch>
  {
    public:
      ObjectDestroy()
        : m_allocationCallbacks( nullptr )
        , m_dispatch( nullptr )
      {}

      ObjectDestroy( Optional<const AllocationCallbacks> allocationCallbacks, Dispatch const &dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
        : m_allocationCallbacks( allocationCallbacks )
        , m_dispatch( &dispatch )
      {}

      Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        VULKAN_HPP_ASSERT( m_dispatch );
        t.destroy( m_allocationCallbacks, *m_dispatch );
      }

    private:
      Optional<const AllocationCallbacks> m_allocationCallbacks;
      Dispatch const* m_dispatch;
  };

  template <typename OwnerType, typename Dispatch>
  class ObjectFree
  {
    public:
      ObjectFree()
        : m_owner()
        , m_allocationCallbacks( nullptr )
        , m_dispatch( nullptr )
      {}

      ObjectFree( OwnerType owner, Optional<const AllocationCallbacks> allocationCallbacks, Dispatch const &dispatch ) VULKAN_HPP_NOEXCEPT
        : m_owner( owner )
        , m_allocationCallbacks( allocationCallbacks )
        , m_dispatch( &dispatch )
      {}

      OwnerType getOwner() const VULKAN_HPP_NOEXCEPT { return m_owner; }
      Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        VULKAN_HPP_ASSERT( m_owner && m_dispatch );
        m_owner.free( t, m_allocationCallbacks, *m_dispatch );
      }

    private:
      OwnerType m_owner;
      Optional<const AllocationCallbacks> m_allocationCallbacks;
      Dispatch const* m_dispatch;
  };

  template <typename OwnerType, typename PoolType, typename Dispatch>
  class PoolFree
  {
    public:
      PoolFree( OwnerType owner = OwnerType(), PoolType pool = PoolType(), Dispatch const &dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
        : m_owner( owner )
        , m_pool( pool )
        , m_dispatch( &dispatch )
      {}

      OwnerType getOwner() const VULKAN_HPP_NOEXCEPT { return m_owner; }
      PoolType getPool() const VULKAN_HPP_NOEXCEPT { return m_pool; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        m_owner.free( m_pool, t, *m_dispatch );
      }

    private:
      OwnerType m_owner;
      PoolType m_pool;
      Dispatch const* m_dispatch;
  };

  template<typename T, size_t N, size_t I>
  class PrivateConstExpression1DArrayCopy
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T * dst, T const* src ) VULKAN_HPP_NOEXCEPT
    {
      PrivateConstExpression1DArrayCopy<T, N, I - 1>::copy( dst, src );
      dst[I - 1] = src[I - 1];
    }
  };

  template<typename T, size_t N>
  class PrivateConstExpression1DArrayCopy<T, N, 0>
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T * /*dst*/, T const* /*src*/ ) VULKAN_HPP_NOEXCEPT
    {}
  };

  template <typename T, size_t N>
  class ConstExpression1DArrayCopy
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T dst[N], const T src[N] ) VULKAN_HPP_NOEXCEPT
    {
      const size_t C = N / 2;
      PrivateConstExpression1DArrayCopy<T, C, C>::copy( dst, src );
      PrivateConstExpression1DArrayCopy<T, N - C, N - C>::copy(dst + C, src + C);
    }

    VULKAN_HPP_CONSTEXPR_14 static void copy( T dst[N], std::array<T, N> const& src ) VULKAN_HPP_NOEXCEPT
    {
      const size_t C = N / 2;
      PrivateConstExpression1DArrayCopy<T, C, C>::copy(dst, src.data());
      PrivateConstExpression1DArrayCopy<T, N - C, N - C>::copy(dst + C, src.data() + C);
    }
  };

  template<typename T, size_t N, size_t M, size_t I, size_t J>
  class PrivateConstExpression2DArrayCopy
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T * dst, T const* src ) VULKAN_HPP_NOEXCEPT
    {
      PrivateConstExpression2DArrayCopy<T, N, M, I, J - 1>::copy( dst, src );
      dst[(I - 1) * M + J - 1] = src[(I - 1) * M + J - 1];
    }
  };

  template<typename T, size_t N, size_t M, size_t I>
  class PrivateConstExpression2DArrayCopy<T, N, M, I,0>
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T * dst, T const* src ) VULKAN_HPP_NOEXCEPT
    {
      PrivateConstExpression2DArrayCopy<T, N, M, I - 1, M>::copy( dst, src );
    }
  };

  template<typename T, size_t N, size_t M, size_t J>
  class PrivateConstExpression2DArrayCopy<T, N, M, 0, J>
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T * /*dst*/, T const* /*src*/ ) VULKAN_HPP_NOEXCEPT
    {}
  };

  template <typename T, size_t N, size_t M>
  class ConstExpression2DArrayCopy
  {
  public:
    VULKAN_HPP_CONSTEXPR_14 static void copy( T dst[N][M], const T src[N][M] ) VULKAN_HPP_NOEXCEPT
    {
      PrivateConstExpression2DArrayCopy<T, N, M, N, M>::copy( &dst[0][0], &src[0][0] );
    }

    VULKAN_HPP_CONSTEXPR_14 static void copy( T dst[N][M], std::array<std::array<T, M>, N> const& src ) VULKAN_HPP_NOEXCEPT
    {
      PrivateConstExpression2DArrayCopy<T, N, M, N, M>::copy( &dst[0][0], src.data()->data() );
    }
  };

  using Bool32 = uint32_t;
  using DeviceAddress = uint64_t;
  using DeviceSize = uint64_t;
  using SampleMask = uint32_t;
} // namespace VULKAN_HPP_NAMESPACE